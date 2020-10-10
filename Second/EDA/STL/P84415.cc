#include <iostream>
#include <map>
using namespace std;

void min(const map<string,int>& bag, map<string,int>::iterator)
{

}

int main()
{
    map<string,int> bag;

    string c;
    while (cin >> c)
    {
        map<string,int>::iterator it;

        if (c == "minimum?")
        {
            if (bag.empty()) cout << "indefinite minimum";
            else
            {
                it = bag.begin();
                cout << "minimum: "  << it->first << ", " << it->second << " time(s)";
            }
            cout << endl;
        }
        else if (c == "maximum?")
        {
            if (bag.empty()) cout << "indefinite maximum";
            else
            {
                it = --bag.end();
                cout << "maximum: " << it->first << ", " << it->second << " time(s)";
            }
            cout << endl;
        }
        else if (c == "delete")
        {
            cin >> c;
            it = bag.find(c);
            if (it != bag.end())
            {
                --it->second;
                if (it->second == 0) bag.erase(c);
            }
            
        }
        else if (c == "store")
        {
            cin >> c;
            it = bag.find(c);
            if (it == bag.end()) bag[c] = 1;
            else ++it->second;
        }
        
    }

}