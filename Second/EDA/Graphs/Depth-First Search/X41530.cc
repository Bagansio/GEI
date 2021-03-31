#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;
//PARA UN GRAFO g MIRA EN LA COMPONENTE CONEXA DE LA ARESTA rc SI HAY ALGUN BUCLE EN CASO AFIRMATIVO DEVUELVE FALSO EN CASO AFIRMATIVO DEVUELVE TRUE
bool bosc(const Matrix& g,vector<bool>& notvis,int r, int c)
{
    int n = g.size();
    if(!notvis[r]) return false;
    notvis[r] = false;
    for(int a: g[r])
    {
        if(a != c and not(bosc(g,notvis,a,r))) return false;
    }
    return true;
}


//PARA UN GRAFO g MIRA TODAS LAS COMPONENTES CONEXAS Y SI ESTAS SON UN BOSQUE O NO, SI 1 COMPONENTE NO ES UN BOSQUE DEVUELVE 0
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
        Matrix g(n);                    //CREAMOS UN GRAFO VACIO
        for(int i = 0; i < m; ++i)      
        {
            int r,c;
            cin >> r >> c;
            g[r].push_back(c);
            g[c].push_back(r);
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