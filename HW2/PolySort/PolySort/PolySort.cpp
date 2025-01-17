﻿#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <sstream>
#include <memory>
#include <exception>
// #include <typeinfo>
#include <algorithm>
#include <functional>
// #include "Source.cpp"
// struct value_visitor;
using namespace std;

class inconsistency_exception : exception
{
public:
	const char* what() const throw() override
	{
		return "Inconsistent rows";
	}
};

struct
{
	istream* input = &cin;
	ostream* output = &cout;
	ifstream infile;
	ofstream outfile;
	char separator = ' ';
	vector<tuple<char, int>> sort_columns;
	vector<char> type_columns;
	const char accepted_types[2] = { 'N', 'S' };
	// map<const char,const string>myID_to_realID = { {'N',typeid(int).name()},{'S',typeid(string).name()} };

} parameters; // for sake of making it easier I do it this static way. If I were to scale it up I would naturaly make instances of this struct

void arg_processing(const size_t argc, const vector<string>& args)
{
	for (size_t i = 0; i < argc; ++i)
	{
		string arg = args[i];
		if (arg.size() < 2)
			throw invalid_argument(arg); // neither option nor collumn can be one char long
		if (arg[0] == '-')
		{
			string val = arg.substr(2);
			if (arg.size() == 2)
			{
				if (i + 1 == argc)
					throw invalid_argument(arg);
				val = args[i + 1];
				++i;
			}
			switch (arg[1])
			{
			case 'i':
			{
				parameters.infile = ifstream(val, ifstream::in);//i need to have it stored somewhere and without using "new" it had to be this way
				parameters.input = &parameters.infile;
				break;
			}
			case 'o':
			{
				parameters.outfile = ofstream(val, ofstream::out);
				parameters.output = &parameters.outfile;
				break;
			}
			case 's':
				if (val.size() > 1)
					throw invalid_argument(arg);
				parameters.separator = val[0];
				break;
			default:
				throw invalid_argument(arg);
			}
		}
		else
		{
			char t;
			bool correct = false;
			for (char type : parameters.accepted_types)
			{
				if (type == arg[0])
				{
					correct = true;
					t = type;
					break;
				}
			}
			if (!correct)
				throw invalid_argument(arg);
			int n;
			if (!isdigit(arg[1]))
				throw invalid_argument(arg); // want to avoid negative numbers and plus sign which would get parsed
			n = stoi(arg.substr(1));		 // would throw invalid_argument if exception which is what I am catching anyway
			parameters.sort_columns.emplace_back(make_tuple(t, n));
		}
	}
}

class abstractvalue
{
public:
	virtual void print() const = 0;
	virtual unique_ptr<abstractvalue> clone() = 0;
	char type = 0;
	virtual bool operator<(abstractvalue& x)const = 0;
};
template <typename T>
class variant final : public abstractvalue
{
public:
	variant(T val)
	{
		type = 'N';
		this->val = val;
	}
	bool operator<(abstractvalue& x)const override {
		if (type == x.type) {
			return *this < *dynamic_cast<variant*>(&x);
		}
		else return false;
	}
	bool operator<(variant& x) const
	{
		return val < x.val;
	}
	unique_ptr<abstractvalue> clone() override
	{
		return make_unique<variant>(*this);
	}
	void print() const override
	{
		cout << val;
	}
	T val;
};

class list
{
public:
	abstractvalue& operator[](const int i) const
	{
		return *inner_list[i];
	}
	list() {}
	void add(string s)
	{
		size_t pos = inner_list.size();
		char required_type = parameters.type_columns[pos];
		switch (required_type)
		{
		case 'N':
			add(make_unique<variant<int>>(stoi(s)));
			break;
		case 'S':
			add(make_unique<variant<string>>(s));
			break;
		default:
			throw exception();
			break;
		}
	}
	void add(unique_ptr<abstractvalue> unique)
	{
		inner_list.push_back(move(unique));
	}
	size_t size()
	{
		return inner_list.size();
	}
	void clone(const list& l)
	{
		for (auto&& x : l.inner_list)
		{
			inner_list.push_back(x->clone());
		}
	}
	void print() const
	{
		size_t cnt = 0;
		for (auto&& cell : inner_list)
		{
			cell->print();
			++cnt;
			if (cnt != inner_list.size())
				cout << parameters.separator;
		}
	}
	list(const list& s) { clone(s); }
	list(list&& other)noexcept {
		inner_list = std::move(other.inner_list);
	}
	list& operator=(const list& s)
	{
		if (this == &s)
			return *this;
		inner_list.clear();
		clone(s);
		return *this;
	};
	list& operator=(list&& s)noexcept
	{
		if (this == &s)
			return *this;
		inner_list = move(s.inner_list);
		return *this;
	};

private:
	vector<unique_ptr<abstractvalue>> inner_list;
};

class table
{
public:
	table() = default;

	void print() const
	{
		for (const list& item : rows)
		{
			item.print();
			cout << endl;
		}
	}
	void sortList(int index)
	{
		sort(rows.begin(), rows.end(), [index](const list& a, const list& b)
			{return a[index] < b[index]; });
	}
	void add(list& l)
	{
		rows.push_back(move(l));
	}

private:
	vector<list> rows;
};

static void prepare_column_types(const size_t len) {
	for (size_t i = 0; i < len; i++) {
		parameters.type_columns.emplace_back('S');
	}
	for (tuple<char, int> col : parameters.sort_columns) {
		char type = get<0>(col);
		if (type != 'S') {
			parameters.type_columns[get<1>(col) - 1] = type;
		}
	}
}

static void parse_input(table& table_)
{
	string line;
	size_t len = 0;
	while (getline(*parameters.input, line))
	{
		list lst;
		size_t start = 0, end = 0;
		if (len == 0) {
			for (char c : line)
			{
				if (c == parameters.separator)++len;
			}
			++len;
			if (len == 0)throw inconsistency_exception();
			prepare_column_types(len);
		}
		while (end != string::npos)
		{
			end = line.find(parameters.separator, start);
			lst.add(line.substr(start, end - start));
			start = end + 1;
		}
		if (len != lst.size())
		{
			throw inconsistency_exception();
		}
		table_.add(lst);
	}
}

int main(const int argc, char* argv[])
{
	// argument processing
	vector<string> args;
	for (int i = 1; i < argc; ++i)
		args.emplace_back(argv[i]);
	try
	{
		arg_processing(static_cast<size_t>(argc) - 1, args);
	}
	catch (invalid_argument& e)
	{
		cerr << e.what();
		return 0;
	}

	table table_;
	// parse input
	try
	{
		parse_input(table_);
	}
	catch (inconsistency_exception& e)
	{
		cerr << e.what();
		return 0;
	}
	catch (exception& e)
	{
		cerr << e.what();
		return 0;
	}
	// sort the table
	for (auto&& col = parameters.sort_columns.rbegin(); col != parameters.sort_columns.rend(); ++col)
	{
		table_.sortList(get<1>(*col) - 1);
	}
	// print the table
	table_.print();
}
