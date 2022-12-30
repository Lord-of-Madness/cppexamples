#include <iostream>
#include <vector>
template<typename T> class RubberArray
{
public:
    RubberArray(int chunk)
    {
	    this->chunk_=chunk;
        bloat_by(1);
        nextfree=&rake_[0][0];
    }
    void push_back(const T& x);
    T& operator[](const int i)
    {
	    return rake_[i/chunk_][i%chunk_];
    }

    
private:
	int chunk_ = 64;
    int chunkCount = 0;
    T* nextfree;
    void bloat_by(int i);
    std::vector<std::unique_ptr<T[]>>rake_;
};

template<typename T>
void RubberArray<T>::push_back(const T& x)
{
    *nextfree=x;
    if(&rake_[chunkCount-1][chunk_-1]==nextfree)
    {
	    bloat_by(1);
        nextfree=&rake_[chunkCount-1][0];
    }
    else ++nextfree;
}

template<typename T>
void RubberArray<T>::bloat_by(int i)
{
    rake_.push_back(std::make_unique<T[]>(chunk_));
    chunkCount++;
}

class iterator
{
	
};


int main()
{
    RubberArray<int> cislicka(2);
    for (int i = 0; i < 5; ++i)
    {
	    cislicka.push_back(i*10);
		std::cout << cislicka[i]<<std::endl;

    }
     
}


