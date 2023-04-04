/*#include "tagged_vector.hpp"

#include "test_util.hpp"

#include <iterator>
#include <type_traits>
#include <iostream>
#include <sstream>
#include <concepts>

struct pear_tag : tag_base {};
struct apple_tag : tag_base {
    using carrier_type = int;
};

struct not_a_tag {};

void test_all(int r)
{
    std::cout << "concept tag"<<std::endl;
    TEMPLATE_TYPE_1_TEST(index_carrier_type, pear_tag, true);
    TEMPLATE_TYPE_1_TEST(index_carrier_type, apple_tag, true);
    TEMPLATE_TYPE_1_TEST(index_carrier_type, not_a_tag, false);
    TEMPLATE_TYPE_2_TEST(vector_class, double, pear_tag, true);
    TEMPLATE_TYPE_2_TEST(vector_class, double, apple_tag, true);
    TEMPLATE_TYPE_2_TEST(vector_class, double, not_a_tag, false);
    TEMPLATE_TYPE_1_TEST(index_class, pear_tag, true);
    TEMPLATE_TYPE_1_TEST(index_class, apple_tag, true);
    TEMPLATE_TYPE_1_TEST(index_class, not_a_tag, false);
    TEMPLATE_TYPE_1_TEST(range_class, pear_tag, true);
    TEMPLATE_TYPE_1_TEST(range_class, apple_tag, true);
    TEMPLATE_TYPE_1_TEST(range_class, not_a_tag, false);

    std::cout << "index_carrier_type" << std::endl;
    TYPE_TEST(index_carrier_type<pear_tag>, std::size_t);
    TYPE_TEST(index_carrier_type<apple_tag>, int);

    std::cout << "index_class size" << std::endl;
    // 
    CONST_TEST(sizeof(index_class<pear_tag>), sizeof(std::size_t));
    CONST_TEST(sizeof(index_class<apple_tag>), sizeof(int));

    std::cout << "index_class" << std::endl;
    // 
    index_class<apple_tag> zero_apple_index(0);
    index_class<apple_tag> positive_apple_index(1);
    index_class<apple_tag> negative_apple_index(-1);

    VALUE_TEST(zero_apple_index.value(), 0);
    VALUE_TEST(negative_apple_index.value(), -1);

    VALUE_TEST(zero_apple_index == negative_apple_index, false);
    VALUE_TEST(zero_apple_index != negative_apple_index, true);

    OSTREAM_TEST(zero_apple_index, "0");
    OSTREAM_TEST(positive_apple_index, "1");
    OSTREAM_TEST(negative_apple_index, "-1");

    std::cout << "default-initialized index_class" << std::endl;
    
    index_class<apple_tag> invalid_apple_index;

    EXCEPTION_TEST(invalid_apple_index.value(), std::range_error);
    EXCEPTION_TEST(invalid_apple_index == negative_apple_index, std::range_error);
    EXCEPTION_TEST(invalid_apple_index != negative_apple_index, std::range_error);
    EXCEPTION_TEST(std::cout << invalid_apple_index, std::range_error);
    EXCEPTION_TEST(index_class<apple_tag> v(invalid_apple_index), std::range_error);
    EXCEPTION_TEST(negative_apple_index = invalid_apple_index, std::range_error);

    std::cout << "range_class" << std::endl;
    // 
    range_class<apple_tag> three_apple_range(-1, 2);
    range_class<apple_tag> four_apple_range(4);
    range_class<pear_tag> four_pear_range(4);

    EQUAL_TEST(four_apple_range, four_pear_range, false);

    VALUE_TEST(four_apple_range == three_apple_range, false);
    VALUE_TEST(four_apple_range != three_apple_range, true);
    VALUE_TEST(four_apple_range == range_class<apple_tag>(0, 4), true);

    std::cout << "range_class iterators" << std::endl;
    // 
    VALUE_TEST(*four_apple_range.begin(), zero_apple_index);
    VALUE_TEST(*three_apple_range.begin(), negative_apple_index);
    VALUE_TEST(*++three_apple_range.begin(), zero_apple_index);
    VALUE_TEST(*--three_apple_range.end(), positive_apple_index);

    using apple_range_iterator = decltype(three_apple_range.begin());
    using pear_range_iterator = decltype(four_pear_range.begin());
    TYPE_TEST(apple_range_iterator::iterator_category, std::bidirectional_iterator_tag);
    TYPE_TEST(apple_range_iterator::value_type, index_class<apple_tag>);
    TYPE_TEST(apple_range_iterator::reference, index_class<apple_tag>);
    TYPE_TEST(apple_range_iterator::difference_type, int);
    TYPE_TEST(pear_range_iterator::difference_type, std::ptrdiff_t);
    
    CONST_TEST(std::bidirectional_iterator<apple_range_iterator>, true);// this ain't workin'

    std::cout << "vector_class" << std::endl;
    // 
    vector_class<double, apple_tag> apple_vector(three_apple_range);

    VALUE_TEST(apple_vector.range() == three_apple_range, true);
    VALUE_TEST(apple_vector.range() != three_apple_range, false);
    EXCEPTION_TEST(apple_vector[invalid_apple_index], std::range_error);

    std::cout << "empty vector_class" << std::endl;
    // 
    vector_class<int, apple_tag> empty_apple_vector;
    VALUE_TEST(empty_apple_vector.range(), range_class<apple_tag>(0, 0));
}

int main(int argc, char** argv)
{
	try {
        int r = 0;
        if (argc >= 2)
            r = std::stoi(argv[1]);

        test_all(r);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}*/
