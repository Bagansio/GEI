#include <iostream>
#include <vector>

using namespace std;

int fixed_point(int a,const vector<int>& v,int l, int r)
{
    if(l > r) return -1;
    int m = (l+r)/2;
    
    if(v[m]+a > m+1) return fixed_point(a,v,l,m-1);
    if(v[m]+a < m+1) return fixed_point(a,v,m+1,r);
    int fp = fixed_point(a,v,l,m-1);
    if(fp == -1) return m+1;
    return fp;    
}

int fixed_point(int a, const vector<int>& v)
{
    return fixed_point(a,v,0,v.size()-1);
}

int main()
{
    int seqNumber = 1;
    int n;
    while(cin >> n)
    {
        cout << "Sequence #" << seqNumber << endl;
        vector<int> v(n);
        for(int& i : v) cin >> i;
        
        int m;
        cin >> m;

        for(int i = 0; i < m; ++i)
        {
            int a;
            cin >> a;
            int fp = fixed_point(a,v);
            if (fp == -1) cout << "no fixed point for " << a;
            else cout << "fixed point for " << a << ": " << fp;
            cout << endl;
        }
        ++seqNumber;
        cout << endl;
    }
}