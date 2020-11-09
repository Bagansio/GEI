#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& list,int l, int r, int m)
{
    vector<int> aux(r-l+1);
    int count = 0;
    int i = l, j = m+1, k = 0;
    while (i <= m and j <= r)
    {
        if (list[i] <= list[j]) aux[k++]=list[i++];
        else
        {
            count += m+1-i;
            aux[k++] = list[j++];
        }
    }
    while(i <= m) aux[k++] = list[i++];
    while(j <= r) aux[k++] = list[j++];
    for(k = 0; k < aux.size(); ++k) list[l+k] = aux[k];
    return count;
}

int inversions(vector<int>& list,int l, int r)
{
    int count = 0;
    if (l < r)
    {
        int m = (l+r)/2;
        count = inversions(list,l,m);
        count += inversions(list,m+1,r);
        count += merge(list,l,r,m);
    }
    return count;
}
int main()
{
    int n;
    while(cin >> n)
    {
        vector <int> list(n);
        for (int i = 0; i < n; ++i) cin >> list[i];
        cout << inversions(list,0,list.size()-1) << endl;
    }
}