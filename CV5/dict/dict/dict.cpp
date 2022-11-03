#include <iostream>
#include <map>
#include <vector>
#include <string>

class MyMap {
    public:
        MyMap();
        ~MyMap();
    std::map<std::string, std::vector<std::string>>* innerMap;
    void Add(const std::string& key, const  std::string& value) {
        if (innerMap->find(key) == innerMap->end()) {
            (*innerMap)[key] = std::vector<std::string>();
        }
        (*innerMap)[key].push_back(value);
    }
    void Remove(const std::string& key, const std::string& value) {
        for (auto i = (* innerMap)[key].begin(); i != (*innerMap)[key].end(); i++) {
            if (*i == value) {
                (*innerMap)[key].erase(i);
                break;
            }

        }
        
    }
    void Remove(const std::string& key) {
        (*innerMap).erase(key);
    }
    const std::vector<std::string>& Find(const std::string &key) {
        return (*innerMap)[key];
    }
    
};
MyMap::MyMap()
{
    innerMap = new std::map<std::string, std::vector<std::string>>();
}

MyMap::~MyMap()
{
    delete innerMap;
}
void ParseCommand(MyMap &dict,std::string &buffer) {
    
    int i = 0;
    while (buffer[i] != ' ') i++;
    std::string command = buffer.substr(0,i);
    i++;

    int j = i + 1;
    while ((j < buffer.length()) && (buffer[j] != ' ')) {
        j++;
    }
    std::string key = buffer.substr(i, j-i);
    
    std::string value;
    if (j < buffer.length()) {
        j++;
        int k = j + 1;
        while ((k < buffer.length()) && (buffer[k] != ' ')) k++;
        value = buffer.substr(j, k-j);
    }
    else value = "";

    if (command == "add") {
        dict.Add(key, value);
        //std::cout<< "Added succesfully"<<std::endl
    }
    else if (command == "del") {
        if (value=="")dict.Remove(key);
        else dict.Remove(key, value);
        //std::cout<< "Removed succesfully"<<std::endl
    }
    else if (command == "find") {
        std::vector<std::string> values = dict.Find(key);
        if (values.size() == 0) {
            std::cout << "There is no such key";
            return;
        }
        std::cout << "values for this key are: ";
        for (std::string v : values)
        {
            std::cout << v << ' ';
        }
        std::cout << std::endl;
    }


}

int main()
{
    MyMap Dict;
    std::string buffer;
    while (std::getline(std::cin, buffer)) ParseCommand(Dict,buffer);

}