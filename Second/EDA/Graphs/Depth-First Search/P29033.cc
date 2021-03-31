#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;


bool colors(const Matrix& g,vector<int>& color,int r, int c,bool prevc)
{
    //cout << r << ' ' << c << ' ' << prevc << ' ' << color[r] << endl;
    int n = g.size();
    int prev;
    if (prevc) prev = 2;
    else prev = 1;
    if(color[r] == prev) return false;
    if(color[r] == 0)
    {
        color[r] = prev%2 + 1;
        for(int a: g[r])
        {
            if(a != c and not colors(g,color,a,r,not prevc)) return false;
        }
    }
    return true;   
}

bool colors(const Matrix& g)
{
    int n = g.size();
    int i = 0;
    int count = 0;
    vector<int> color (n,0);
    for(int i = 0; i < n; ++i)
    {
        if(color[i] == 0)
        {
            if(not colors(g,color,i,0,true)) return false;
        }   
    }
    return true;    
}

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        Matrix g(n);                    //CREAMOS UN GRAFO VACIO
        for(int i = 0; i < m; ++i)      
        {
            int r,c;
            cin >> r >> c;
            g[r].push_back(c);
            g[c].push_back(r);
        }
        if (colors(g)) cout << "yes";
        else cout << "no";
        cout << endl;
/*
        for(vector<bool> r : g)
        {
            for(bool x : r) cout << x << ' ';
            cout << endl;
        }
        */


    }
}