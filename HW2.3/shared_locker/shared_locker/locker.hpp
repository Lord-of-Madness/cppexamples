#ifndef INTERVAL_LOCKER
#define INTERVAL_LOCKER

#include <mutex>
#include <condition_variable>
#include "interval_tree.hpp"
#include <limits>
#include <thread>

class locker;
class exclusive_lock;

class shared_lock {
	//friend class locker;
public:
	using size_type = std::size_t;
	shared_lock()noexcept :cv(nullptr), locker_(nullptr), key({ 0,0 }) {}  // produce invalid object
	shared_lock(const shared_lock&) = delete; // no support for copy
	shared_lock(shared_lock&& other) noexcept :valid(false) {// move + invalidate source object
		*this = std::move(other);
	}
	shared_lock(std::condition_variable* cv, locker* l, std::pair<size_type, size_type> k) :cv(cv), locker_(l), key(k), valid(true) {}
	shared_lock& operator=(const shared_lock&) = delete; // no support for copy
	shared_lock& operator=(shared_lock&& other) noexcept {
		if (this != &other) {
			if (valid) {// unlock `*this` (if valid)
				unlock();
			}
			// move
			cv = other.cv;
			locker_ = other.locker_;
			valid = other.valid;
			key = other.key;
			
			other.valid = false;//invalidate source object
		}
		return *this;
	}

	exclusive_lock upgrade();
	~shared_lock() noexcept {
		if (valid) unlock();// unlock (if not invalid)
	}
	void unlock() noexcept;

private:
	std::condition_variable* cv;
	locker* locker_;
	std::pair<size_type, size_type> key;
	bool valid=false;
};

class exclusive_lock {
public:
	using size_type = std::size_t;
	exclusive_lock()noexcept :cv(nullptr), locker_(nullptr), key({ 0,0 }) {}  // produce invalid object

	exclusive_lock(const exclusive_lock&) = delete; // no support for copy
	exclusive_lock(exclusive_lock&& other) noexcept {// move + invalidate source object
		*this = std::move(other);
	}
	exclusive_lock& operator=(const exclusive_lock&) = delete; // no support for copy
	exclusive_lock& operator=(exclusive_lock&& other) noexcept {
		if (this != &other) {

			if (valid) {// unlock `*this` (if valid)
				unlock();
			}
			// move
			cv = other.cv;
			locker_ = other.locker_;
			valid = other.valid;
			key = other.key;
			
			other.valid = false;//invalidate source object
		}
		return *this;
	}

	~exclusive_lock() {
		if (valid)unlock();// unlock (if not invalid)
	}
	void unlock() noexcept;
	shared_lock downgrade() noexcept;
	exclusive_lock(std::condition_variable* cv, locker* l, std::pair<size_type, size_type>& key) :cv(cv), locker_(l), key(key), valid(true) {}
private:
	std::condition_variable* cv;
	locker* locker_;
	std::pair<size_type, size_type> key;
	bool valid = false;
};


class locker {
	friend class shared_lock;
	friend class exclusive_lock;
public:
	using size_type = std::size_t;
	locker() {}

	locker(const locker&) = delete; // no support for copy
	locker(locker&&) = delete; // no support for move
	locker& operator=(const locker&) = delete; // no support for copy
	locker& operator=(locker&&) = delete; // no support for move

	~locker() {
		lock_exclusive(0, std::numeric_limits<size_type>::max());// BLOCKING, wait until all locks are removed
	}

	shared_lock lock_shared(const size_type b, const size_type e) {
		std::pair interval(b, e);
		std::unique_lock<std::mutex> lock(mtx);// BLOCKING
		//ThreadQueue?
		cv.wait(lock, [this, interval] {return exclusive_tree.get_overlap(interval) == exclusive_tree.end(); });
		addInterval(interval,shared_tree);
		
		return shared_lock(&cv, this, interval);//create a shared_lock
	}
	exclusive_lock lock_exclusive(const size_type b, const size_type e) {
		std::pair interval(b, e);
		std::unique_lock<std::mutex> lock(mtx);// BLOCKING
		cv.wait(lock, [this, interval] {return (exclusive_tree.get_overlap(interval) == exclusive_tree.end()) && (shared_tree.get_overlap(interval) == shared_tree.end()); });
		addInterval(interval,exclusive_tree);
		
		return exclusive_lock(&cv, this, interval);//create an exclusive_lock
	}
	void addInterval(const std::pair<size_type, size_type>& interval, interval_tree<size_t>& tree) {
		interval_tree<size_t>::node* query = tree.find(interval);
		if (query == nullptr)tree.emplace(interval, 1);
		else ++query->value;
	}
	void removeInterval(const std::pair<size_type, size_type>& interval, interval_tree<size_t>& tree) {
		interval_tree<size_t>::node* query = tree.find(interval);
		if (query->value == 1) {
			tree.erase(interval);
			//cv.notify_all();Cannot do -> They are locked at this point and To do it elsewhere would help just Unlock functions not the *grade functions who need to swap in one go.
		}
		else --query->value;
	}
private:
	interval_tree<size_t> shared_tree;
	std::mutex mtx;
	std::condition_variable cv;
	interval_tree<size_t> exclusive_tree;
};











/*
	Every lock is associated with an interval `[b,e)`.
	Intervals `[b1,e1)` and `[b2,e2)` overlap if `b1<e2 && b2<e1`.
	Two locks with overlapping intervals may simultaneously exist only if both are shared.

	`lock_...` and `upgrade` function will not return until all conflicting locks are unlocked by their holders.
	`~locker` destructor will not return until all locks are unlocked by their holders.

	There are no timeouts and no deadlock prevention/detection.
	(Deadlock detection is impossible because there are no defined owners (transactions/threads/...) of the locks.)

	`locker` object must be thread-safe (`lock_...` functions may be called simultaneously from many threads).
	Each `..._lock` object will be used only by one thread; therefore the object alone does not have to be thread-safe.
*/

#endif // !INTERVAL_LOCKER