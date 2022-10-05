#include <iostream>
#include <vector>
#include <string>
using namespace std;

int whatever(const string& s) {
    std::cout << s << std::endl;
    //stringy pøedávat takhle - referencí
    return 0;
}

void nasobilkuj(const vector<string>& a){
    //std::string s = std::to_string(a);
    for (int i = 1; i < a.size(); i++) {
        for (int j = 1; j <= 10; j++) {
            std::cout << std::stoi(a[i])*j << std::endl;
        }
        
    }
}

int main(int argc,char ** argv)
{
    //std::cout << "Hello World!" << std::endl;
    vector<string> arg( argv, argv+argc);
    
    nasobilkuj(arg);
    
    return 0;
}


// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
