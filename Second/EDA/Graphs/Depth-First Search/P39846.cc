#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;


int farest_treasure(const vector<string>& map,int i, int j)
{
    int n = map.size();
    int m = map[0].size();
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    int ft = -1;
    queue< pair< pair<int,int>,int> > Q;
    
    
    Q.push({{i,j},0});

    while(! Q.empty())
    {
        i = Q.front().first.first;
        j = Q.front().first.second;
        int distance = Q.front().second;
        Q.pop();
        if(!(i < 0 or i == map.size() or j < 0 or j == map[0].size() or map[i][j] == 'X' or vis[i][j]))
        {
            vis[i][j] = true;
            if(map[i][j] == 't' and distance > ft) ft = distance;
            Q.push({{i+1,j},distance+1});
            Q.push({{i-1,j},distance+1});
            Q.push({{i,j+1},distance+1});
            Q.push({{i,j-1},distance+1});
        } 
    }
    return ft;
}

int main()
{
    int r,c;
    cin >> r >> c;
    vector<string> map(r);
    for(string& s : map) cin >> s;
    cin >> r >> c;
    int ft = farest_treasure(map,r-1,c-1);
    if (ft == -1) cout << "no es pot arribar a cap tresor";
    else cout << "distancia maxima: " << ft;
    cout << endl;
}