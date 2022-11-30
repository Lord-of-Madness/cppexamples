// ReSharper disable IdentifierTypo
#include <iostream>
#include <memory>
#include <vector>
class fruit
{
public:
	virtual void print()=0;
	virtual std::unique_ptr<fruit> clone()=0;
};
class jablko:public fruit
{
public:
	explicit jablko(int const weight)
		: weight(weight)
	{
	}
	void print() override
	{
		std::cout <<"The chonk is: "<<weight<<std::endl;
	}
	std::unique_ptr<fruit> clone() override
	{
		return std::make_unique<jablko>(*this);
	}

private:
	int weight;
};
class hruska:public fruit
{
public:
	explicit hruska(const std::string& quality)
    {
	    this->quality=quality;
    }
	void print() override
	{
		std::cout <<"The quality is: "<<quality<<std::endl;
	}

    std::unique_ptr<fruit> clone() override
	{
		return std::make_unique<hruska>(*this);
	}
private:
	std::string quality;
};
class Seznam
{
public:
	void clone(const Seznam& seznam)
	{
		for(auto&& x:seznam.pole){pole.push_back(x->clone());}
	}

	Seznam(const Seznam& s){clone(s);}
	Seznam(){}

	Seznam& operator=(const Seznam& s)
    {
	    if(this==&s)return *this;
        pole.clear();
        clone(s);
        return *this;
    };

	void print()
	{
		for(auto && item : pole){item->print();}
	}
	void add(std::unique_ptr<fruit> unique)
	{
		pole.push_back(move(unique));
	}

private:
    std::vector<std::unique_ptr<fruit>> pole;
};

int main()
{
    Seznam s,s2;
    s.add(std::make_unique<jablko>(5));
    s.add(std::make_unique<hruska>("hezka"));
	s2 = s;
    s.print();
	std::cout<<"s2:"<<std::endl;
	s2.print();
}
