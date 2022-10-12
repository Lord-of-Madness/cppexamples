#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct{
    int od = 1;
    int Do = 10; 
}Bounds;

void zpracujArg(vector<string>& s) {
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
                    Bounds.od = stoi(s[i + 1]);
                    
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
                    Bounds.Do = stoi(s[i + 1]);
                }
                catch (exception) {
                    cerr << "Wrong (likely non inteager) parameter\n";
                }
                s.erase(s.begin() + i, s.begin() + i + 2);
                i--;
            }
        }
    }
    if (Bounds.od > Bounds.Do) {
        cerr << "It seems you swapped -f and -t I shall swap them for you\n";
        swap(Bounds.od, Bounds.Do);
    }
}

void nasobilkuj(const string& a){
    //std::string s = std::to_string(a);
    for (int j = Bounds.od; j <= Bounds.Do; j++) {
        try{
            cout << a 
            <<'*' << j << '=' 
            << stoi(a) * j << endl; }
        catch (exception) {
            cerr << "Oh dear - it seems "<< a << " appears to be a mischevious argument! How queer!\n";
            break;
        }
    }
    
}



int main(int argc,char ** argv)
{
    vector<string> arg( argv, argv+argc);
    
    zpracujArg(arg);
    for(string a:arg){
        nasobilkuj(a);
        cout << "\n";
    }
    //nasobilkuj("72");
    return 0;
}