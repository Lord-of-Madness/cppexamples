#include "file_access.h"
#include <exception>
#include<map>
#include<deque>


template <typename ValueType, size_t arity, typename EvictionPolicy>
class cached_container;

template < typename ValueType, size_t arity, typename EvictionPolicy>
class pers_ptr;

template<typename ValueType, size_t arity, typename EvictionPolicy>
struct node : public persistent_node<ValueType, arity> {
	using pers_ptr_t = pers_ptr<ValueType, arity, EvictionPolicy>;
	using p_n = persistent_node<ValueType, arity>;
	using cc = cached_container<ValueType, arity, EvictionPolicy>;
public:
	node(internal_ptr ip=null_internal_ptr, cc* cache=nullptr) : ip(ip), value(*ip),cache(cache) {}//only here is the actual lookup to the data
	void get_ptr() {
		++ptr_counter;
	}
	pers_ptr_t get_child(size_t index) {
		return &cache->operator[](p_n::ptr[index]);
	}
	void release_ptr() {
		--ptr_counter;
		cache->release_ptr(ip);
	}
	ValueType value;
	size_t ptr_counter = 0;
	internal_ptr ip;
private:
	cc* cache;
};


template < typename ValueType, size_t arity, typename EvictionPolicy>
class pers_ptr {
public:
	pers_ptr(const pers_ptr&) = delete;
	pers_ptr(pers_ptr&& other) noexcept :data(std::move(other.data)) {}
	pers_ptr(node<ValueType, arity, EvictionPolicy>* data) : data(data) {
		data->get_ptr();
	}
	~pers_ptr() {
		data->release_ptr();
	}
	pers_ptr& operator=(const pers_ptr&) = delete;
	pers_ptr& operator=(pers_ptr&& other) noexcept {
		if (other.data == this->data)return *this;
		data = std::move(other.data);
		return *this;
	}
	explicit operator bool() const noexcept {
		if (data->ip == null_internal_ptr)return false;
		return true;
	}
	pers_ptr get_ptr(size_t index) {
		if (index >= arity)throw std::exception("get_ptr: index was greater then arity");
		return data->get_child(index);
	}
	const ValueType& operator*() {
		return data->value;
	}
	const ValueType* operator->() {//returns a pointer to the cached val
		return &data->value;
	}
	/* other public methods may be IMPLEMENTATION-DEFINED */
private:
	node<ValueType, arity, EvictionPolicy>* data;

};






template <typename ValueType, size_t arity, typename EvictionPolicy>
class cached_container {
	using pp = pers_ptr<ValueType, arity, EvictionPolicy>;
	using node_t = node<ValueType, arity, EvictionPolicy>;
public:
	cached_container(file_descriptor fd, size_t size) :fd(fd), cache_capacity(size) {

	}
	pp root_ptr() {
		return &root_node;
	}
	pp null_ptr() {
		return &null_node;
	}
	void release_ptr(internal_ptr p) {
		ep->unlock(p);
	}
	/* other public methods may be IMPLEMENTATION-DEFINED */
	node_t& operator[](internal_ptr key) {
		if (cache.contains(key)) {
			node_t n = cache[key];
			if (n.ptr_counter == 0)ep->relock(key, 0);
			return cache[key];//double lookup but I don't want to handle auto inserting keys and other options looked too clunky

		}
		if (cache.size() >= cache_capacity - 1) {
			cache.erase(ep->release());
		}
		ep->load(key);
		ep->relock(key, 0);
		cache[key] = node(key,this);
	}
private:
	file_descriptor fd;
	std::map<internal_ptr, node_t> cache;
	size_t cache_capacity;
	EvictionPolicy* ep;
	node_t root_node = node( root_internal_ptr,this );
	node_t null_node = node(null_internal_ptr,this);
};





class EvictionOldestUnlock {
public:
	using hint_type = internal_ptr;
	void load(internal_ptr ptr) {}                  // new cache node loaded from file
	hint_type unlock(internal_ptr ptr)           // cached node unlocked (free to release)
	{
		oldest.push_back(ptr);
		return ptr;//random retrun
	}
	void relock(internal_ptr ptr, hint_type)     // previously unlocked node from the cache that is locked again
	{
		auto it = oldest.begin();
		while (*it != ptr)++it;
		oldest.erase(it);
	}
	internal_ptr release()                    // eviction victim to be released
	{
		internal_ptr ip = oldest.front();
		oldest.pop_front();
		return ip;
	}
private:
	std::deque<hint_type> oldest;//Not sure whats the best data structure but I needed a queue with erase. (Apparently std::queue is just restricted deque and doesn't have erase)
	//If evicitonPolicy doesn't have access to the cache(which is how the framework seem to be designed) then it must keep records of some kind
};