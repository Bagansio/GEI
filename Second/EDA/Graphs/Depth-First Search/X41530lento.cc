#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<bool>> Matrix;

bool bosc(const Matrix& g,vector<bool>& notvis,int r, int c)
{
    int n = g.size();
    if(!notvis[r]) return false;
    notvis[r] = false;
    for(int i = 0; i < n; ++i)
    {
        if(g[r][i] and i != c and not(bosc(g,notvis,i,r))) return false;
    }
    return true;
}

int bosc(const Matrix& g)
{
    int n = g.size();
    int i = 0;
    int count = 0;
    vector<bool> notvis (n,true);
    for(int i = 0; i < n; ++i)
    {
        if(notvis[i])
        {
            if(bosc(g,notvis,i,0)) ++count;
            else return 0;
        }   
    }
    return count;    
}
int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        Matrix g(n,vector<bool>(n,false));
        for(int i = 0; i < m; ++i)
        {
            int r,c;
            cin >> r >> c;
            g[r][c] = g[c][r] = true;
        }
        int b = bosc(g);
        if (b == 0) cout << "no";
        else cout << b;
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