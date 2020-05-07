#include <iostream>
#include <set>
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


int main() {
    set<string> totes, cap, falta;
    string x;
    while (cin >> x and x != ".") totes.insert(x);
    cap = totes;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        falta = totes;
        while (cin >> x and x != ".") {
            cap.erase(x);
            falta.erase(x);
        }

        for (set<string>::iterator it = falta.begin(); it != falta.end(); ++it) totes.erase(*it);
    }
    cout << "Totes les activitats:";
    escriure_set(totes);
    cout << "Cap activitat:";
    escriure_set(cap);
}