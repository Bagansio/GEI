#include <iostream>
#include <vector>
using namespace std;

void i_subst_sum(vector<int>& v, int i, int& s)
{
    if (i < v.size())
    {
        s += v[i];
        i_subst_sum(v,i+1,s);
    }
}

void subst_sum(vector<int>& v)
{
    i_subst_sum(v,1,v[0]);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    subst_sum(v);
    for (int i = 0; i < n; ++i) cout << v[i];
}