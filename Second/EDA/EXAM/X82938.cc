#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int top(const vector<int>& v, int l, int r) {
    if (l + 1 >= r) {
        if (v[l] < v[r]) return r;
        else return l ;
    }
    int m = (l+r)/2;
    if (v[m - 1] > v[m]) return top(v, l , m - 1);
    if (v[m + 1] > v[m]) return top(v, m + 1, r);
    return m;
}
bool bin_search (bool inc , const vector<int>& v, int l, int r, int x) {
    if (l == r) return v[l] == x;
    int m = (l+r)/2;
    bool cond;
    if (inc ) cond = (x <= v[m]);
    else cond = (x >= v[m]);
    if (cond) return bin_search (inc , v, l , m, x );
    else return bin_search (inc , v, m+1, r, x );
}
bool search (int x, const vector<int>& v) {
    int n = v. size ();
    int t = top(v, 0, n - 1);
    return bin_search (true, v, 0, t, x) or bin_search (false , v, t, n - 1, x);
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int m;
        cin >> m;
        while (m--) {
          int x;
          cin >> x;
          cout << ' ' << search(x, V);
        }
        cout << endl;
    }
}