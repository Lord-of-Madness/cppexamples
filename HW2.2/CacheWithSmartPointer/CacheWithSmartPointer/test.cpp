#include "pers_ptr.h"
#include <cstdint>
#include <array>
#include <iostream>


struct MyData {
	uint32_t i32;
	std::array<char, 8> ca;
};



void f( const MyData&) {}

int main()
{
	cached_container< MyData, 2, EvictionOldestUnlock> cc{ 100, 0 };
	auto other_ptr = cc.null_ptr();                        			// null (invalid) ptr
	uint32_t sum = 0;
	for( auto p = cc.root_ptr(); p; p = p.get_ptr(0)) {    // traversing from the root ptr while the following ptr is valid
		f(*p);                                             // MyData&
		other_ptr = p.get_ptr(1);

		sum += p->i32 * (other_ptr ? other_ptr->i32 : 1);
	}
	std::cout << sum;
	return 0;
}
