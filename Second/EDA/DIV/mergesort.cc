#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& v, int l, int r, int m)
{
    vector<int> auxr(r - m);
    vector<int> auxl(m - l + 1);
    for (int i = 0; i < r - m; ++i)
    {
        auxr[i] = v[m + 1 + i];
    }
    for (int i = 0; i < m - l + 1; ++i)
    {
        auxl[i] = v[l + i];
    }

    int i = 0;
    int j = 0;
    while (i < auxl.size() and j < auxr.size())
    {
        if (auxl[i] < auxr[j])
        {
            v[l] = auxl[i];
            ++i;
        }
        else
        {
            v[l] = auxr[j];
            ++j;
        }
        ++l;
    }

    while (i < auxl.size())
    {
        v[l] = auxl[i];
        ++i;
        ++l;
    }
    while (j < auxr.size())
    {
        v[l] = auxr[j];
        ++j;
        ++l;
    }
}

void mergesort(vector<int>& v, int l, int r)
{
    cout << r << ' ' << l << endl;
    
    if (r - l > 0)
    {
        int m = (l+r) / 2;
        mergesort(v,l,m);
        mergesort(v,m + 1,r);

        merge(v,l,r,m);
    }
}

int main()
{
    vector<int> v;
    int n;
    while(cin>>n && n != 0) v.push_back(n);
    for(int n : v) cout << n << endl;
    cout <<"--------------------"<< endl;
    mergesort(v,0,v.size()-1);
    for(int n : v) cout << n << endl;
}