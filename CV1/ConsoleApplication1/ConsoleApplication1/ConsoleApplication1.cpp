#include <iostream>
#include <vector>
#include <string>
using namespace std;

void zpracujArg(vector<string>& s, int& od, int& Do) {
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]=="-f")
        {
            if (i + 1 >= s.size()) {
                cerr << "You forgot the parameter!\n";
                s.erase(s.begin() + i);
                i--;
            }
            else {
                try{
                    od = stoi(s[i + 1]);
                    
                }
                catch (exception) {
                    cerr << "Wrong (likely non inteager) parameter\n";
                }
                s.erase(s.begin() + i, s.begin() + i + 2);
                i--;
            }
        }
        else if(s[i] == "-t")
        {
            if (i + 1 >= s.size()) {
                cerr << "You forgot the parameter!\n";
                s.erase(s.begin() + i);
                i--;
            }
            else {
                try {
                    Do = stoi(s[i + 1]);
                }
                catch (exception) {
                    cerr << "Wrong (likely non inteager) parameter\n";
                }
                s.erase(s.begin() + i, s.begin() + i + 2);
                i--;
            }
        }
    }
    if (od > Do) {
        cerr << "It seems you swapped -f and -t I shall swap them for you\n";
        swap(od, Do);
    }
}

void nasobilkuj(const vector<string>& a, int od,int Do){
    //std::string s = std::to_string(a);
    for (int i = 1; i < a.size(); i++) {
        for (int j = od; j <= Do; j++) {
            try{
            cout << stoi(a[i])<<'*' << j << '=' << stoi(a[i]) * j << endl; }
            catch (exception) {
                cerr << "Oh dear - it seems "<< a[i] << " appears to be a mischevious argument! How queer!\n";
                break;
            }
        }
        cout << "\n";
    }
}

int main(int argc,char ** argv)
{
    vector<string> arg( argv, argv+argc);
    int od = 1;
    int Do = 10;
    zpracujArg(arg,od,Do);
    nasobilkuj(arg,od,Do);
    
    return 0;
}