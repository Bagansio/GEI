#include <list>
#include <iostream>
using namespace std;

int main()
{
    list<int> l;
    pair<int,int> parell;
    int max = 0, min = 0;
    double sum = 0;
    while (cin >> parell.first >> parell.second and parell.first != 0)
    {
        if (parell.first == -1) //s'afegeix
        {
            if (l.empty())
            {
                max = min = parell.second;
            }
            else
            {
                if (max < parell.second) max = parell.second;
                if (min > parell.second) min = parell.second;
            }
            sum += parell.second;
            l.push_back(parell.second);
        }
        else if (not l.empty())//es borra
        {
            list<int>::iterator it = l.begin();
            bool found = false;
            while (it != l.end() and not found)
            {
                if ((*it) == parell.second){
                    sum -= parell.second;
                    it = l.erase(it);
                    found = true;
                }
                else ++it;
            }
            if (not l.empty() and (parell.second == min or parell.second == max))
            {
                list<int>::const_iterator it = l.begin();
                min = *it;
                max = *it;
                while (it != l.end()) {
                    if (max < *it) max = *it;
                    if (min > *it) min = *it;
                    ++it;
                }
            }
        }
        if (l.empty())
        {
            cout << '0';
        }
        else cout << min << ' ' << max << ' ' << sum/l.size();
        cout << endl;
    }
}