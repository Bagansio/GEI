#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define Matrix vector<string>

bool found_t(const  vector<string>& board)
{
    for(auto row: board)
        for(auto c: row) if(c == 'T') return true;

    return false;
}

bool pos_notok(int i, int j, const vector<string>& board,const vector<vector<bool>>& vis)
{
    return (i < 0 or j < 0 or i >= board.size() or j >= board[0].size() or board[i][j] == '#' or vis[i][j]);
}

void found(const vector<string>& board,int n,int m)
{
    int d = 100;
    int p = 0;
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    queue<pair<pair<int,int>,pair<int,int>>> Q;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    Q.push({{0,0},{0,0}});
    
    while(not Q.empty())
    {
        int i = Q.front().first.first;
        int j = Q.front().first.second;
        int paux = Q.front().second.second;
        int daux = Q.front().second.first;
        Q.pop();
        
        if(board[i][j] == 'P') ++paux;
        if(board[i][j] == 'T')
        {
            //cout << i << ' ' << j << ' ' << d << ' ' << daux << " l " << p << ' ' << paux << endl;
            //cout << daux << ' ' << d << " l " << paux << ' ' << p << endl;
            if(daux < d) 
            {
                d = daux;
                p = paux;
            }
            if(daux == d and paux > p) p = paux;
        }
        for(int k = 0; k < dirs.size(); ++k)
        {
            int iaux = i + dirs[k][0];
            int jaux = j+dirs[k][1];

            if(not pos_notok(iaux,jaux,board,vis))
            {
                vis[i][j] = true;
                Q.push({{iaux,jaux},{daux+1,paux}});
            }
        }
    }
    if(d != 100) cout << d << ' ' << p;
    else if(found_t(board)) cout << "El telecos esta amagat.";
    else cout << "El telecos ha fugit."; 
    cout << endl;
}

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        vector<string> board(n);
        for(string& s : board) cin >> s;
        

        found(board,n,m);
    }
}