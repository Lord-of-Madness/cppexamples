class shared_lock {
public:
    shared_lock() noexcept;  // produce invalid object

    shared_lock(const shared_lock&) = delete; // no support for copy
    shared_lock(shared_lock&&) noexcept; // move, invalidate source object
    shared_lock& operator=(const shared_lock&) = delete; // no support for copy
    shared_lock& operator=(shared_lock&&) noexcept; // unlock `*this` (if not invalid), move, invalidate source object

    ~shared_lock() noexcept; // unlock (if not invalid), noexcept by default

    void unlock() noexcept;  // unlock (if not invalid), invalidate
    exclusive_lock upgrade();   // BLOCKING, upgrade to exclusive_lock, invalidate `*this`
};

class exclusive_lock {
public:
    exclusive_lock() noexcept;  // produce invalid object

    exclusive_lock(const exclusive_lock&) = delete; // no support for copy
    exclusive_lock(exclusive_lock&&) noexcept; // move, invalidate source object
    exclusive_lock& operator=(const exclusive_lock&) = delete; // no support for copy
    exclusive_lock& operator=(exclusive_lock&&) noexcept; // unlock `*this` (if not invalid), move, invalidate source object

    ~exclusive_lock(); // unlock (if not invalid), noexcept by default

    void unlock() noexcept;  // unlock (if not invalid), invalidate
    shared_lock downgrade() noexcept;   // downgrade to shared_lock, invalidate `*this`
};


class locker {
public:
    using size_type = std::size_t;
    locker();

    locker(const locker&) = delete; // no support for copy
    locker(locker&&) = delete; // no support for move
    locker& operator=(const locker&) = delete; // no support for copy
    locker& operator=(locker&&) = delete; // no support for move

    ~locker();  // BLOCKING, wait until all locks are removed

    shared_lock lock_shared(size_type b, size_type e);  // BLOCKING, create a shared_lock
    exclusive_lock lock_exclusive(size_type b, size_type e);    // BLOCKING, create an exclusive_lock
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
