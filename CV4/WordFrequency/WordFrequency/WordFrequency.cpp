#include <iostream>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
//#include <functional>


class freqCount
{
public:
	freqCount();
	~freqCount();
    void addWord(std::string);
    const std::map<std::string, int>& getDict();
private:
    std::map<std::string, int> *dict;
};

freqCount::freqCount()
{
    dict = new std::map<std::string, int>();
}

freqCount::~freqCount()
{
    delete dict;
}

void freqCount::addWord(std::string key) {
    (*dict)[key]++;
}

const std::map<std::string, int>& freqCount::getDict() {
    return *dict;
}

void forEachWord(freqCount &counter,void (freqCount::*func)(std::string)) {
    std::string word;
    while (std::cin>>word){
        (counter.*func)(word);
    }
}
void forEachWord(std::istream *stream, freqCount& counter, void (freqCount::* func)(std::string)) {
    std::string word;
    while (*stream >> word) {
        (counter.*func)(word);
    }
}


int main(int argc, char const* const* argv)
{
    freqCount *Counter = new freqCount();
    if (argc == 1) {
        forEachWord(*Counter,&freqCount::addWord);
    }
    else {
        for (int i = 1; i < argc; i++) {
            std::ifstream *is= new std::ifstream(argv[i]);
            forEachWord(is, *Counter, &freqCount::addWord);
        }
    }
    std::map<std::string, int > dict = Counter->getDict();
    for (std::map<std::string, int >::const_iterator it = dict.begin();
        it != dict.end(); ++it)
    {
        std::cout << it->first << ": " << it->second << "\n";
    }
    //IO 
    //forEachWord that takes stream and a function and applies the function on each word of the stream
    //the wordCounter will accept words and can be asked for the dict its making
}
