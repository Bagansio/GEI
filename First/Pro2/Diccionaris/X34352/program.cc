#include <map>
#include <iostream>
using namespace std;

void accio(map<string, int>& d, char code, string s)
{
    map<string, int>::iterator it = d.find(s);
    if (code == 'a')  //suma
    {
        if (it == d.end()) d.insert(make_pair(s,1));
        else d[s] = it -> second + 1;
    }
    else if (code == 'f') //cout
    {
        if (it == d.end()) cout << 0;
        else cout << it -> second;
        cout << endl;
    }
    else if (code == 'e') //decrementa
    {
        if (it != d.end()){
            if (it -> second > 0) d[s] = it -> second - 1;
            else  d.erase(it);
        }
    }
}

int main()
{
    map<string, int> d;
    char code;
    string s;
    while (cin >> code >> s)
    {
        accio(d,code,s);
    }

}