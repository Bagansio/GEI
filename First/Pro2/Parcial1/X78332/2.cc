#include <iostream>
#include <list>
using namespace std;

void reverse_prefix(list<int>& l, list<int>::iterator it) {
    list<int>::iterator p = l.begin();
    while (it != p)
    {
        l.push_front(*it);
        l.erase(it);
        --it;
    }
}

int main(){
    list<int> l;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int j;
        cin >> j;
        l.push_back(j);
    }
    list<int>::iterator it = l.begin();
    for (int i = 0; i < 5; ++i) ++it;
    cout << 5 << endl;
    reverse_prefix(l,it);
    cout << "yes" << endl;
       for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        cout << *it << ' ';
    }
}