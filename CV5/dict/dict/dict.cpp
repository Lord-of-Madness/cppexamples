#include <iostream>
#include <map>
#include <vector>
#include <string>

class MyMap {
    std::map<std::string, std::vector<std::string>> innerMap;
    void Add(const std::string& key, const  std::string& value) {
        if (innerMap.find(key) == innerMap.end()) {
            innerMap.insert(std::pair<std::string, std::vector<std::string>>(key, std::vector<std::string>()));
        }
        innerMap[key].push_back(value);
    }
    void Remove(const std::string& key, const std::string& value) {
        for (auto i = innerMap[key].begin(); i != innerMap[key].end();i++) {
            if (*i == value) {
                innerMap[key].erase(i);
                break;
            }

        }
        
    }
    void Remove(const std::string& key) {
        innerMap.erase(key);
    }
    const std::vector<std::string>& Find(const std::string &key) {
        return innerMap[key];
    }
    
};

int main()
{
    MyMap Dict;


}