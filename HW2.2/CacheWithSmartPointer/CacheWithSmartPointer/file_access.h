#ifndef FILE_ACCESS_H__
#define FILE_ACCESS_H__


#include <array>
#include <unordered_map>

using file_descriptor = int ;			// some sort of magic
using internal_ptr = long ;		// internal persistent ptr === item _index_ within the file (0-based)
constexpr internal_ptr null_internal_ptr = -1 ;
constexpr internal_ptr root_internal_ptr = 0;		// ptr to the root item

// persistent data structure
template <typename ValueType, size_t arity>
struct persistent_node {
	ValueType value;
	std::array< internal_ptr, arity> ptr;
};

struct MyData {
	int value;

	MyData(int value) : value(value) { }
	MyData() : value(-1) { }
};

template <typename PersistentData>
class storage {
public:
	std::unordered_map<internal_ptr, PersistentData> value = {};
};


template <>
class storage<persistent_node<MyData, 2>> {
public:
	std::unordered_map<internal_ptr, persistent_node<MyData, 2>> value = { { 0, persistent_node<MyData, 2>{MyData(0), { 1, 2 }} },
																				{ 1, persistent_node<MyData, 2>{MyData(1), { 2, 2 }} },
																				{ 2, persistent_node<MyData, 2>{MyData(2), { 0, 1 }} } };
};

template <typename T>
class file_access {
public:
	file_access() { 
		//init(); 
	}
	bool read(file_descriptor fd, internal_ptr ip, T& item) {
		item = data.value[ip];
		return false;
	}
private:
	storage<T> data{};
};

/* specializations IMPLEMENTATION-DEFINED */

#endif
