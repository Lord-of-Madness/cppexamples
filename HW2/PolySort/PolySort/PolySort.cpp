#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <typeinfo>
#include <map>
using namespace std;
struct {
	istream* input = &cin;
	ostream* output = &cout;
	char separator = ' ';
	vector<tuple<char, int>> sort_columns;
	const char accepted_types[2] = {'N','S'};
	map<const char,const string>myID_to_realID = { {'N',typeid(int).name()},{'S',typeid(string).name()} };

}parameters;//for sake of making it easier I do it this static way. If I were to scale it up I would naturaly make instances of this struct

void arg_processing(const int argc, const vector<string>& args)
{
	for (int i = 0; i < argc; ++i)
	{
		string arg = args[i];
		if (arg.size() < 2)throw invalid_argument(arg);//neither option nor collumn can be one char long
		if (arg[0] == '-')
		{
			string val = arg.substr(2);
			if (arg.size() == 2)
			{
				if (i + 1 == argc)throw invalid_argument(arg);
				val = args[i + 1];
				++i;
			}
			switch (arg[1])
			{
			case 'i':
			{ifstream infile(val, ifstream::in);
			parameters.input = &infile;
			break; }
			case 'o':
			{ofstream outfile(val, ofstream::out);
			parameters.output = &outfile;
			break; }
			case 's':
				if(val.size()>1)throw invalid_argument(arg);
				parameters.separator = val[0];
				break;
			default:
				throw invalid_argument(arg);
			}
		}
		else
		{
			char t;
			for(char type :parameters.accepted_types)
			{
				if (type == arg[0]) {
					t = type; break;
				}
			}
			int n;
			if(!isdigit(arg[1]))throw invalid_argument(arg);//want to avoid negative numbers and plus sign which would get parsed
			n = stoi(arg.substr(1));//would throw invalid_argument if exception which is what I am catching anyway
			parameters.sort_columns.emplace_back(make_tuple( t,n ));
		}
	}

}



/*class polyItem
{
public:
	polyItem() = default;

	polyItem(string type, void* data)
		: type_(move(type)),
		  data_(data)
	{
	}
	tuple<string,void*> getdata()
	{
		return { type_,data_ };
	}
private:
	string type_;//so I would like it if I could store the actual type however in C++ type is not a real thing its more like a weird reference to some obscure object and I din't want to deal with that (but it could be probably optimized as a pointer to type)
	void* data_{};//alright hear me out: this may look scary but how else am I supposed to store the values as their own types other then void pointers + type info?
};*/
/*template<typename T>
class polyItem2
{
public:
	polyItem2() = default;

	polyItem2( T data)
		: data_(data)
	{
	}
	T getdata()
	{
		return data_;
	}
private:
	T data_;
};*/

class poly_vector
{
public:
	poly_vector(const int len) :len_(len) { vecCount = 0; }
	void sort(const tuple<char,int> &col)
	{
		const string type = parameters.myID_to_realID[get<0>(col)];
		int collumn = get<1>(col);
		map<polyItem,vector<polyItem>> items;
		for (size_t i = 0;i<in_vector_.size();i++)
		{
			items.insert(in_vector_[i][collumn],&in_vector_[i]);
		}

	}
	void add(vector<string> &thing_to_add)
	{
		//(typeid(T).name(), thing_to_add)
		vector<polyItem> ar(len_);
		for (string& item : thing_to_add)
		{
			bool is_number = true;
			for(const char c : item)
			{
				if (!isdigit(c)) { is_number = false; break; }
			}
			if(is_number)
			{
				int x = stoi(item);
				ar.emplace_back(typeid(int).name(), &x);//oh no x gets lost in the void right?
			}
			else
			{
				ar.emplace_back(typeid(string).name(), &item);
			}
		}
		in_vector_.emplace_back(ar);
		++vecCount;
	}
private:
	int vecCount;
	const int len_;
	vector<vector<polyItem>> in_vector_;//I tried to make it a vector of fixed size arrays but couldn't figure out how to set the fixed size dynamicaly and without new() It might have been a silly idea but it was on the edge of possibility
};

poly_vector parse_input()
{
	string line;
	size_t len = 0;
	//getline(*parameters.input,line);
	//const int len = line.size();
	poly_vector v(len);
	while (parameters.input->eofbit)
	{
		getline(*parameters.input, line);
		if (len == 0)len = line.size();
		else if (len != line.size())throw "Inconsistent rows";//lazy to write my own exception
		vector<string> vs(len);
		unsigned int start = 0U;
		auto end = line.find(parameters.separator);
		while (end != std::string::npos)
		{
			vs.emplace_back(line.substr(start, end - start));
			start = end + 1;
			end = line.find(parameters.separator, start);
		}
		v.add(vs);

	}
}

int main(const int argc, char** argv)
{
	vector<string> args;
	for (int i = 1; i < argc; ++i)
		args.emplace_back(argv[i]);
	try {
		arg_processing(argc - 1, args);
	}
	catch (invalid_argument& e)
	{
		cout << e.what();
		return 0;
	}
	catch (string &e)
	{
		cout << e;
		return 0;
	}
	poly_vector poly_v = parse_input();
	
	// parsování vstupu
	for (auto &col:parameters.sort_columns)
	{
		poly_v.sort(col);
	}
	//sorter
	// printni polymorfní array
}