#include <iostream>
#include <set>

class T {public: std::string s;  int i; };
struct comparator {
    bool operator()(const T& x,const T& y) const
    {
        return x.i < y.i || (x.i == y.i && x.s < y.s);
    }
};

auto cmp = [](const T& x, const T& y) {return x.i < y.i || (x.i == y.i && x.s < y.s); };


class T2 {
    std::string s; int i;
    bool operator<(const T& y) const
    {
        return i < y.i || (i == y.i && s < y.s);
    }
};






int main()
{
    std::set<T, comparator> v0;
    v0.insert(T{"jedna",1 });
    std::set< T, decltype(cmp)> v1;
    v1.insert(T{ "jedna",1 });
    std::set<T> v2;
    v2.insert(T{ "jedna", 1 });
}
