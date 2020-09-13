#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

struct compare
{
    bool operator()(const string& a, const string& b)
    {
        if (a.length() == b.length()) return a < b;
        return a.length() < b.length();
    }
};

void end_game(const set<string>& S, const set<string,compare>& R)
{
    cout << "HAS:" << endl;
    for(string x : S) cout << x << endl;
    cout << endl;
    cout << "HAD:" << endl;
   for(string x : R) cout << x << endl;
}


int main()
{
    set<string> S;
    set<string,compare> R;
    string word;
    int game = 1;
    
    cout << "GAME #1" << endl;
    while (cin >> word and word != "QUIT")
    {
        if (word == "END")
        {
            end_game(S,R);
            S = set <string>();
            R = set <string,compare>();
            ++game;
            cout << endl << "GAME #" << game << endl;
        }
        else 
        {
            if (S.find(word) == S.end())
            {
                S.insert(word);
                R.erase(word);
            }
            else
            {
                S.erase(word);
                R.insert(word);
            }
        }
    }
    end_game(S,R);
}