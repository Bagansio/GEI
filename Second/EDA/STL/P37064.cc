#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<string> S;
    
    string word;
    cin >> word;
    if (word != "END")
    {
        S.insert(word);
        set<string>::iterator it = S.begin();
        cout << word << endl;
        while (cin >> word and word != "END")
        {
            S.insert(word);
            if (word < *it and S.size() % 2 == 0) --it;
            else if (word > *it and S.size() % 2 != 0) ++it;
            cout << *it << endl;
        }
    }
}