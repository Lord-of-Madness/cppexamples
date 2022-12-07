#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int y = 2;
    vector<int> test = {1,2,3,4,5,6,7,8,9,10};
    for_each(test.cbegin(), test.cend(), cout<<[y](int &x) {return x *y; });
    //for_each(test.cbegin(), test.cend(), [](int x) { x; });
}