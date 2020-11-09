#include <iostream>
#include <vector>
using namespace std;

bool i_resistant_search(double x, const vector<double>& v, int l, int r)
{
    if (l > r) return false;
    if (l == r) return v[l] == x;
    int m = (l+r)/2;
    if (v[m] == x or (m > 0 and v[m-1] == x) or (m < v.size() and v[m+1] == x)) return true;
    if (v[m] > x) return i_resistant_search(x,v,l,m-1);
    return i_resistant_search(x,v,m+1,r);
}

bool resistant_search(double x, const vector<double>& v)
{
    return i_resistant_search(x,v,0,v.size()-1);
}


int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << resistant_search(x, V) << endl;
        }
    }
}
