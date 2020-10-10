#include <iostream>
#include <set>
using namespace std;

int main()
{
    int x,y,n;
    while (cin >> x >> y >> n)
    {
        bool big = false;
        set<int> S,C;
        while (not big and C.find(n) == C.end())
        {
           
            if (S.find(n) == S.end()) S.insert(n);
            else C.insert(n);
            if (n%2 == 0) n = n/2+x;
            else n = 3*n + y;
            if (n > 100000000) big = true;

        }
        if (big) cout << n;
        else cout << C.size();
        cout << endl;
    }
}