#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

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
	MyMap();
	~MyMap();
	dictionary* innerMap;
	void Add(const std::string& key, const  std::string& value) {
		if (innerMap->find(key) == innerMap->end()) {
			(*innerMap)[key] = dictValue();
		}
		(*innerMap)[key].insert(value);
	}
	void Remove(const std::string& key, const std::string& value) {
		for (auto i = (*innerMap)[key].begin(); i != (*innerMap)[key].end(); i++) {
			if (*i == value) {
				(*innerMap)[key].erase(i);
				break;
			}

		}
		if ((*innerMap)[key].size() == 0)(*innerMap).erase(key);
	}
	void Remove(const std::string& key) {
		(*innerMap).erase(key);
	}
	const dictValue& Find(const std::string& key) {
		return (*innerMap)[key];
	}
	const dictionary::iterator FindAt(const std::string& key) {
		return (*innerMap).find(key);
	}

};
MyMap::MyMap()
{
	innerMap = new dictionary();
}

MyMap::~MyMap()
{
	delete innerMap;
}
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
void ParseCommand(MyMap& dict, const std::string& buffer) {
	if (buffer.length() == 0)return;
	unsigned short i = 0;
	while ((i < buffer.length() - 1) && (buffer[i] != ' ')) i++;
	std::string command = buffer.substr(0, i);
	transform(command.begin(), command.end(), command.begin(), ::tolower);
	i++;
	if (i >= buffer.length())return;
	unsigned short j = i + 1;
	while ((j < buffer.length()) && (buffer[j] != ' ')) {
		j++;
	}
	std::string key = buffer.substr(i, j - i);
	transform(key.begin(), key.end(), key.begin(), ::tolower);
	std::string value;
	if (j < buffer.length()) {
		j++;
		unsigned short k = j + 1;
		while ((k < buffer.length()) && (buffer[k] != ' ')) k++;
		value = buffer.substr(j, k - j);
	}
	else value = "";
	transform(value.begin(), value.end(), value.begin(), ::tolower);
	if (command == "add") {
		dict.Add(key, value);
		//std::cout<< "Added succesfully"<<std::endl
	}
	else if (command == "del") {
		if (value == "")dict.Remove(key);
		else dict.Remove(key, value);
		//std::cout<< "Removed succesfully"<<std::endl
	}
	else if (command == "find") {
		if (dict.innerMap->count(key) == 0)return;
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
		if (dict.innerMap->count(key) == 0) {
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
		if (iter == dict.innerMap->end())return;
		while (true) {
			if (Isprefix(iter->first, key)) {
				std::cout << iter->first << ": ";
				for (std::string v : iter->second)
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
	std::string buffer;
	while (std::getline(std::cin, buffer)) {
		ParseCommand(Dict, buffer);
	}

}