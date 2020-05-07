#include <list>
#include <iostream>
using namespace std;

list<int>::iterator parte_list(list<int>& l, int x)
{
    list<int>::iterator  i = l.begin();
    list<int>::iterator  end = l.end();
    for(list<int>::iterator  it = i; it != end; ++it)
    {
        if (*it > x)
        {
            l.push_back(*it);
            l.erase(it);
        }
        else ++i;
    }
    return i;
}