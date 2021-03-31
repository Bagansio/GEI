#include <iostream>
#include <vector>
using namespace std;

bool arribable(const vector<string>& mapa, int f, int c, vector<vector<bool>>& vis)
{
    int n = mapa.   size();
    int m = mapa[0].size();
    if(not(f >= 0 and f < n and c >= 0 and c < m) or vis[f][c] or mapa[f][c] == 'X') return false;
    vis[f][c] = true;
    if (mapa[f][c] == 't') return true;
    return
        arribable(mapa,f,c-1,vis) or 
        arribable(mapa,f,c+1,vis) or 
        arribable(mapa,f-1,c,vis) or 
        arribable(mapa,f+1,c,vis);
}

bool arribable(const vector<string>& mapa, int f, int c)
{
    int n = mapa.   size();
    int m = mapa[0].size();
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    return arribable(mapa,f,c,vis);
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<string> mapa(n);
    for(string& s : mapa) cin >> s;
    int f,c;
    cin >> f >> c;
    if (arribable(mapa, f-1,c-1)) cout << "yes" << endl;
    else                          cout << "no"  << endl;
}