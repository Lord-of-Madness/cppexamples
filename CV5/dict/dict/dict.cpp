#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <stdio.h>

struct comparator {
	bool operator()(const std::string& x, const std::string& y) const
	{
		if (x.length() < y.length()) return true;
		else if (x.length() == y.length()) return x.compare(y) < 0;
		else return false;
	}
};
using dictValue = std::set<std::string, comparator >;
using dictionary = std::map<std::string, dictValue>;

class MyMap {
public:
	/*MyMap();
	~MyMap();*/
	dictionary innerMap;
	void Add(const std::string& key, const  std::string& value) {
		dictValue& Dvalue = innerMap[key];
		if (innerMap[key].size() == 0) {
			Dvalue = dictValue();
		}
		Dvalue.insert(value);
	}
	void Remove(const std::string& key, const std::string& value) {
		dictValue& Dvalue = innerMap[key];
		auto i = Dvalue.find(value);
		if(i!= Dvalue.end())
			Dvalue.erase(i);

		if (Dvalue.empty())innerMap.erase(key);
	}
	void Remove(const std::string& key) {
		innerMap.erase(key);
	}
	const dictValue& Find(const std::string& key) {
		return innerMap[key];
	}
	const dictionary::iterator FindAt(const std::string& key) {
		return innerMap.find(key);
	}
	const size_t Count(const std::string& key) {
		return innerMap.count(key);
	}
};
/*MyMap::MyMap()
{
	innerMap = dictionary();
}

MyMap::~MyMap()
{
	delete innerMap;
}
*/
bool Isprefix(const std::string& key, const std::string& prefix) {
	if (key.size() < prefix.size()) return false;
	for (unsigned short c = 0; c < prefix.size(); c++)//Hehe c++
	{
		if (key[c] != prefix[c]) {
			return false;
		}
	}
	return true;
}
void ParseCommand(MyMap& dict, const std::string& command, const std::string& key, const std::string& value) {
	//std::cout << command<<std::endl;
	//std::cout << key << std::endl;
	//std::cout << value << std::endl;
	/*
	if (buffer.length() == 0)return;
	unsigned short i = 0;
	while ((i < buffer.length() - 1) && (buffer[i] != ' ')) i++;
	std::string command = buffer.substr(0, i);
	i++;
	if (i >= buffer.length())return;
	unsigned short j = i + 1;
	while ((j < buffer.length()) && (buffer[j] != ' ')) {
		j++;
	}
	std::string key = buffer.substr(i, j - i);
	std::string value;
	if (j < buffer.length()) {
		j++;
		unsigned short k = j + 1;
		while ((k < buffer.length()) && (buffer[k] != ' ')) k++;
		value = buffer.substr(j, k - j);
	}
	else value = "";*/
	
	if (command == "add") {
		dict.Add(key, value);
		//std::cout << "Added succesfully: "<<key << (int)(key[key.length()-1])<< std::endl;
	}
	else if (command == "del") {
		if (value == "")dict.Remove(key);
		else dict.Remove(key, value);
		//std::cout << "Removed succesfully" << std::endl;
	}
	else if (command == "find") {
		//std::cout << "finding key: "<<key << std::endl;
		//std::cout << dict.Count(key) << key << (int)(key[key.length() - 1]) << std::endl;
		if (dict.Count(key) == 0)return;
		dictValue values = dict.Find(key);
		if (values.size() == 0) {
			//std::cout << "There is no such key";
			return;
		}
		//std::cout << "values for this key are: ";
		for (std::string v : values)
		{
			std::cout << v << ' ';
		}
		std::cout << std::endl;
	}
	else if (command == "prefix") {
		bool isprefixkey;
		if (dict.Count(key) == 0) {
			isprefixkey = false;
			dict.Add(key, "");
		}
		else {
			isprefixkey = true;
		}
		dictionary::iterator iter = dict.FindAt(key);
		if (!isprefixkey) {
			iter++;
			dict.Remove(key);
		}
		if (iter == dict.innerMap.end())return;
		while (true) {
			if (Isprefix(iter->first, key)) {
				std::cout << iter->first << ": ";
				for (const std::string& v : iter->second)
				{
					std::cout << v << ' ';
				}
				std::cout << std::endl;
				iter++;
			}
			else break;
		}
	}
}

int main()
{
	MyMap Dict;
	std::string cmd, k, v;
	char command[7], key[101], value[101];
	int retVal;
	std::string buffer;
	while (std::getline(std::cin, buffer))
	{
		//std::cout << buffer << std::endl;
		retVal = sscanf(buffer.c_str(),"%6s %100s %100s", command, key, value);
		if (retVal == EOF)continue;
		cmd = command;
		k = key;
		v = value;
		if (retVal == 2)v = "";
		transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
		transform(k.begin(), k.end(), k.begin(), ::tolower);
		transform(v.begin(), v.end(), v.begin(), ::tolower);
		ParseCommand(Dict, cmd, k, v);
	}
	

}