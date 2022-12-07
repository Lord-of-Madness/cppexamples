#include <iostream>
#include <string>
template <typename T> class zlomek {
public:
    zlomek<T>(const T &cit,const T &jmen) {
        citatel_ = cit;
        jmenovatel_ = jmen;
    }
    zlomek<T>() = default;
    zlomek<T>(const zlomek<T> &x)
    {
	    citatel_ = x.citatel_;
        jmenovatel_ = x.jmenovatel_;
    }
    template<typename T>
    friend zlomek<T> operator+(const zlomek<T>& x, const zlomek<T>& y);
    template<typename T>
    friend std::ostream& operator<<(std::ostream& os, const zlomek<T>& obj);
    T get()const {
        return citatel_/jmenovatel_;
    }
    bool operator< (const zlomek<T>& rhs) { return this.get()<rhs.get(); }
	bool operator> (const zlomek<T>& rhs) { return rhs < this; }
	bool operator<=(const zlomek<T>& rhs) { return !(this > rhs); }
	bool operator>=(const zlomek<T>& rhs) { return !(this < rhs); }
    bool operator==(const zlomek<T>& rhs) { return this.get()==rhs.get(); }
	bool operator!=(const zlomek<T>& rhs) { return !(this == rhs); }
    zlomek<T>& operator=(const zlomek<T>& x);
private:
    T citatel_;
    T jmenovatel_;
};

template <typename T>
zlomek<T>& zlomek<T>::operator=(const zlomek<T>& x)
{
	if(this!=&x)
	{
		jmenovatel_=x.jmenovatel_;
		citatel_=x.citatel_;
	}
	return *this;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const zlomek<T>& obj)
{
    os<<obj.get()<<std::endl;
    return os;
}

template<typename T>
zlomek<T> operator+(const zlomek<T>& x, const zlomek<T>& y) {
    return zlomek<T>{ x.citatel_ * y.jmenovatel_ + y.citatel_ * x.jmenovatel_, y.jmenovatel_ * x.jmenovatel_ };
}//not gonna do it optimally - too lazy

/*
#pragma region DAsimple



class DAsimple {
public:
    DAsimple(int val) {
        v_ = val;
    }
    friend DAsimple operator+(const DAsimple& x, const DAsimple& y);
private:
    int v_;
};
DAsimple operator+(const DAsimple& x, const DAsimple& y) {
    return DAsimple{ x.v_ + x.v_ + y.v_ + y.v_ };
}
#pragma endregion
*/



template<typename X>class DA {
public:
	DA<X>(X val) {
        v_ = val;
    }
    DA<X>() = default;
    template<typename X>
    friend DA<X> operator+(const DA<X>& x, const DA<X>& y);
    template<typename X>
    friend std::ostream& operator<<(std::ostream& os, const DA<X>& obj);
    X get() const{
        return v_;
    }
    bool operator==(const DA<X>& rhs)const { return this.v_==rhs.v_; }
    DA<X>& operator=(const DA<X>& x);
private:
    X v_;
};

template <typename X>
DA<X>& DA<X>::operator=(const DA<X>& x)
{
    if(this!=&x)this.v_=x.v_;
    return *this;
}

template<typename X>
DA<X> operator+(const DA<X>& x, const DA<X>& y) {
    return DA<X>{ x.v_ + x.v_ + y.v_ + y.v_ };
}

template<typename X>
std::ostream& operator<<(std::ostream& os, const DA<X>& obj)
{
    os<<obj.get()<<std::endl;
    return os;
}

int main()
{
    //Could declare it more stylishly but ReSharper kept complaining about it and that annoyed me more

	const DA<int> a = 5;
	const DA<int> b = 7;
    DA<int> c = a + b;
    std::cout << c;
	const DA<std::string> a2 = std::string("Bob");
	const DA<std::string> b2 = std::string("Harry");
    DA<std::string> c2 = a2 + b2;
    std::cout << c2;
	const DA<zlomek<double>> a3 = zlomek<double>(5.5, 5.7);
	const DA<zlomek<double>> b3 = zlomek<double>(11.5, 3.7);
    DA<zlomek<double>> c3 = a3 + b3;
    std::cout << c3;
}

