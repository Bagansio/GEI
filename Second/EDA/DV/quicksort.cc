#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& v, int l, int r)
{
    int p = v[l];
    ++r;
    --l;
    while(true)
    {
        while (v[++l] < p and l < v.size());
        while (v[--r] > p and r > 0);
        if (l >= r) return r; 
        swap (v[l],v[r]);

    }
}

void quicksort(vector<int>& v, int l, int r)
{
    if (l < r)
    {
        int p = partition(v, l, r);     //parting
        //for(int n : v) cout << n << ' ' << l << ' ' << r << ' ' << p << endl;
        quicksort(v,l,p);           //LEFT side recursive sorting
        quicksort(v,p+1,r);         //RIGHT side recursive sorting
    }

}

int main()
{
    vector<int> v;
    int n;
    while(cin>>n && n != 0) v.push_back(n);
    for(int n : v) cout << n << endl;
    cout <<"--------------------"<< endl;
    quicksort(v,0,v.size()-1);
    for(int n : v) cout << n << endl;
}