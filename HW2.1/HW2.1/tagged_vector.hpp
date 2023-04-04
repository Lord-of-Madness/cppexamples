#include <vector>
#include <type_traits>
#include <iostream>
#include <limits>

struct tag_base {};
struct magic_tag :tag_base {};
struct super_magic_tag :tag_base {
	using carrier_type = int;
};

template<typename T>
concept Tag = std::is_base_of_v<tag_base,T>; 



template<Tag T>
struct helper { using ict = std::size_t; };

template<Tag T>
	requires requires {typename T::carrier_type; }
struct helper<T> { using ict = T::carrier_type; };




template<typename T>using index_carrier_type = typename helper<T>::ict;









template<Tag T>
class index_class {
	index_carrier_type<T> index;
public:
	index_class(): index(std::numeric_limits<index_carrier_type<T>>::max()){}

	index_class(const index_class<T>& other) :index(other.value()) {  }

	index_class<T>& operator=(const index_class<T>& other) {
		if (this == &other)return *this;
		index = other.value();
		return *this;
	}
	explicit index_class(const index_carrier_type<T> index) :index(index) {}

	index_carrier_type<T> value()const {
		if (index == std::numeric_limits<index_carrier_type<T>>::max())throw std::range_error("Uninitialized index");
		return index;
	}
	bool operator==(const index_class<T> b)const {
		if (value() == b.value())return true;
		return false;
	}
};

template<Tag T>
struct tag_iterator {
	using iterator_category = std::bidirectional_iterator_tag;
	typedef std::make_signed<index_carrier_type<T>>::type make_signed_t;
	using difference_type = make_signed_t;
	using value_type = index_class<T>;
	using reference = index_class<T>;


	index_carrier_type<T> val;

	tag_iterator() {}//invalid


	tag_iterator(const index_carrier_type<T> val) :val(val) {}

	tag_iterator(const tag_iterator<T>& other) :val(other.val) {}

	tag_iterator<T>& operator=(const tag_iterator<T>& other) {
		//if(other.val== std::numeric_limits<index_carrier_type<T>>::max())throw std::range_error("Uninitialized index");
		if (this == &other)return *this;
		val = other.val;
		return *this;
	}

	index_class<T> operator*()const {
		//if (val == std::numeric_limits<index_carrier_type<T>>::max())throw std::range_error("Uninitialized index");
		return index_class<T>(val);
	}
	tag_iterator<T>& operator++() {
		//if (val == std::numeric_limits<index_carrier_type<T>>::max())throw std::range_error("Uninitialized index");
		val++;
		return *this;
	}
	tag_iterator<T> operator++(int) {
		//if (val == std::numeric_limits<index_carrier_type<T>>::max())throw std::range_error("Uninitialized index");
		tag_iterator<T> old = *this;
		++(*this);
		return old;
	}
	tag_iterator<T>& operator--() {
		//if (val == std::numeric_limits<index_carrier_type<T>>::max())throw std::range_error("Uninitialized index");
		val--;
		return *this;
	}
	tag_iterator<T> operator--(int) {
		//if (val == std::numeric_limits<index_carrier_type<T>>::max())throw std::range_error("Uninitialized index");
		tag_iterator<T> old = *this;
		--(*this);
		return old;
	}
	bool operator==(const tag_iterator<T>& other)const {
		//if (val == std::numeric_limits<index_carrier_type<T>>::max()|| other.val == std::numeric_limits<index_carrier_type<T>>::max())throw std::range_error("Uninitialized index");
		if (val == other.val)return true;
		return false;
	}

};

template<Tag T>
class range_class {

	index_carrier_type<T> start;
	index_carrier_type<T> end_index;
public:
	range_class(const index_carrier_type<T> start, const index_carrier_type<T> end) : start(start), end_index(end) {}
	explicit range_class(const index_carrier_type<T> end) :
		start(0),
		end_index(end)
	{}
	range_class(const range_class<T>& rc):
		start(rc.start),
		end_index(rc.end_index)
	{}
	range_class( range_class<T>&& rc) :
		start(std::move(rc.start)),
		end_index(std::move(rc.end_index))
	{}
	range_class<T>& operator=(const range_class<T> other) {
		if (this == &other)return *this;
		start= other.start;
		end_index= other.end_index;
		return *this;
	}


	tag_iterator<T> begin()const {
		return tag_iterator<T>(start);
	}
	tag_iterator<T> end()const {
		return tag_iterator<T>(end_index);
	}
	bool operator==(const range_class<T>& b)const {
		if (start == b.start && end_index == b.end_index)return true;
		return false;
	}
	index_carrier_type<T> lenght() const {
		return end_index - start;
	}
};


template<typename T, Tag T2>
class vector_class {
	range_class<T2> rng;
	std::vector<T> core_vector;
public:
	vector_class() :rng(0) {}
	explicit vector_class(const range_class<T2>& rng, const T val=T()) :
		rng(rng),
		core_vector(rng.lenght(), val) {}
	/*explicit vector_class(const range_class<T2>& rng) :
		rng(rng),
		core_vector(rng.lenght(), T())
	{}*/
	vector_class(const vector_class<T, T2>& other) :
		rng(other.rng),
		core_vector(other.core_vector)
	{}
	vector_class(vector_class<T, T2>&& o) :
		rng(std::move(o.rng)),
		core_vector(std::move(o.core_vector))
	{}
	T& operator[](const index_class<T2> inx) {
		return core_vector[inx.value()-rng.begin().val];
	}
	const T& operator[](const index_class<T2> inx)const {//propagate constness
		return core_vector[inx.value() - rng.begin().val];
	}
	range_class<T2> range()const { return rng; }//Don't want to return by reference because I don't want anyone to touch my range_class
	
};




template<Tag T>
std::ostream& operator<<(std::ostream& stream, index_class<T>& i) {
	return stream << i.value();
}


