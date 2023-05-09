#include "file_access.h"
#include<unordered_map>
#include<list>

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
	node(const internal_ptr ip = null_internal_ptr, cc* cache = nullptr) : ip(ip), cache(cache) {}
	node(const internal_ptr ip, cc* cache,const p_n pn) : ip(ip), cache(cache) {
		p_n::value = pn.value;
		p_n::ptr = pn.ptr;
	}
	void increment_counter() {
		++ptr_counter;
	}
	pers_ptr_t get_child(const size_t index) {
		return &cache->operator[](p_n::ptr[index]);
	}
	void release_ptr() {
		--ptr_counter;
		if (ptr_counter == 0)
			cache->release_ptr(ip);
	}
	internal_ptr ip;
	size_t ptr_counter = 0;
	EvictionPolicy::hint_type hint{};
private:
	cc* cache;
};


template < typename ValueType, size_t arity, typename EvictionPolicy>
class pers_ptr {
public:
	pers_ptr(const pers_ptr&) = delete;
	pers_ptr(pers_ptr&& other) noexcept :data(std::move(other.data)) { 
		data->increment_counter();
	}
	pers_ptr(node<ValueType, arity, EvictionPolicy>* data) : data(data) {
		data->increment_counter();
	}
	~pers_ptr() {
		data->release_ptr();
	}
	pers_ptr& operator=(const pers_ptr&) = delete;
	pers_ptr& operator=(pers_ptr&& other) noexcept {
		if (other.data == data)return *this;
		if(data->ip!=null_internal_ptr)
			data->release_ptr();
		data = std::move(other.data);
		data->increment_counter();
		return *this;
	}
	explicit operator bool() const noexcept {
		if (data->ip == null_internal_ptr)return false;
		return true;
	}
	pers_ptr get_ptr(size_t index) {
		if (index >= arity)throw "get_ptr: index was greater then arity";
		return data->get_child(index);
	}
	const ValueType& operator*() {
		return data->value;
	}
	const ValueType* operator->() {
		return &data->value;
	}
private:
	node<ValueType, arity, EvictionPolicy>* data;

};






template <typename ValueType, size_t arity, typename EvictionPolicy>
class cached_container {
	using pp = pers_ptr<ValueType, arity, EvictionPolicy>;
	using node_t = node<ValueType, arity, EvictionPolicy>;
	using hint_type = EvictionPolicy::hint_type;
public:
	cached_container(size_t size,file_descriptor fd) :cache_capacity(size), fd(fd) {
		cache.reserve(size);
	}
	pp root_ptr() {
		return &this->operator[](root_internal_ptr);
	}
	pp null_ptr() {
		return &null_node;
	}
	void release_ptr(internal_ptr p) {
		cache[p].hint = ep.unlock(p);
	}
	node_t& operator[](internal_ptr key) {
		if (key == null_internal_ptr)return null_node;
		auto i = cache.find(key);
		if (cache.end()!=i) {
			node_t& n = i->second;
			if (n.ptr_counter == 0)ep.relock(key, n.hint);
			return n; 
		}
		if (cache.size() >= cache_capacity) {
			cache.erase(ep.release());
		}
		ep.load(key);
		persistent_node<ValueType, arity> new_node{};

		fa.read(fd, key, new_node);
		return cache[key] = node_t(key, this, new_node);
	}
private:
	std::unordered_map<internal_ptr, node_t> cache;
	size_t cache_capacity;
	file_descriptor fd;
	EvictionPolicy ep{};
	node_t null_node = node(null_internal_ptr, this);
	file_access<persistent_node<ValueType, arity>> fa{};
};





class EvictionOldestUnlock {
public:
	using hint_type = std::list<internal_ptr>::const_iterator;
	void load(internal_ptr ptr) {}                  // new cache node loaded from file
	hint_type unlock(internal_ptr ptr)           // cached node unlocked (free to release)
	{
		oldest.push_back(ptr);
		return --oldest.cend();
	}
	void relock(internal_ptr ptr, hint_type it)     // previously unlocked node from the cache that is locked again
	{
		oldest.erase(it);
	}
	internal_ptr release()                    // eviction victim to be released
	{
		internal_ptr ip = oldest.front();
		oldest.pop_front();
		return ip;
	}
private:
	std::list<internal_ptr> oldest;
};