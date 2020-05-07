#include <set>
#include <iostream>
#include <string>
using namespace std;

void escriure_set(const set<string>& S)
{
    for (set<string>::iterator it = S.begin(); it != S.end(); ++ it)
    {
        cout << ' ' << *it;
    }
    cout << endl;
}

set<string> lectura(set<string>& totes)
{
    set<string> cap = totes;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        set<string> alguna = totes;
        string s;
        while (cin >> s and s != ".")
        {
            cap.erase(s);
            alguna.erase(s);
        }
        for(set<string>::iterator it = alguna.begin(); it != alguna.end(); ++it)
        {
            totes.erase(*it);
        }
    }
    return cap;
}

int main()
{
    set<string> totes,cap,alguna;
    string s;
    while (cin >> s and s != ".")
    {
        totes.insert(s);
    }
    cap = lectura(totes);
    cout << "Totes les activitats:";
    escriure_set(totes);
    cout << "Cap activitat:";
    escriure_set(cap);
}