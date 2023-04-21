#ifndef FILE_ACCESS_H__
#define FILE_ACCESS_H__


#include <array>

using file_descriptor = int ;			// some sort of magic
using internal_ptr = int* ;		// internal persistent ptr === item _index_ within the file (0-based)
constexpr internal_ptr null_internal_ptr = nullptr ;
constexpr internal_ptr root_internal_ptr = nullptr;		// ptr to the root item

// persistent data structure
template <typename ValueType, size_t arity>
struct persistent_node {
	ValueType value;
	std::array< internal_ptr, arity> ptr;
};


template <typename T>
class file_access {
public:
	file_access() { 
		//init(); 
	}
	bool read(file_descriptor fd, internal_ptr ip, T& item) {

	}
private:
	/* IMPLEMENTATION-DEFINED */
};

/* specializations IMPLEMENTATION-DEFINED */

#endif
