#include <iostream>
#include <random>
using namespace std;
const int MAX = 100;

int main()
{
	default_random_engine generator;
	uniform_int_distribution<int> distrib{ 1,MAX };
	size_t limit = distrib(generator);
	//int ar[MAX];
	try {
		while (true) {
			size_t i = distrib(generator);
			if (i >= limit)throw exception("You are out!");
		}
	}
	catch (exception &e) {
		cout << e.what();
	}
}