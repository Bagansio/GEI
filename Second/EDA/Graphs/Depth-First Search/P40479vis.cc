#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef vector<vector<char>> Board;
typedef vector<vector<bool>> Visited;

void print_board(Board& b, Visited& vis, stack<pair<int,int>>& q,char& c)
{
    if(not q.empty())
    {
        int n = b.   size();
        int m = b[0].size();
        int i = q.top().first;
        int j = q.top().second;
        if(i >= 0 and j >= 0 and i < n and j < m and not vis[i][j])
        {
            vis[i][j] = true;
            if(b[i][j] != '.')
            {
                c = b[i][j];
            }
            
            if(i != 0 and b[i - 1][j] != '#')
            {
                q.push(make_pair(i-1,j));
                print_board(b,vis,q,c);
            }
            if(i != n-1 and b[i + 1][j] != '#')
            {
                q.push(make_pair(i+1,j));
                print_board(b,vis,q,c);
            }
            if(j != 0 and b[i][j-1] != '#')
            {
                q.push(make_pair(i,j-1));
                print_board(b,vis,q,c);
            }
            if(j != m-1 and b[i][j+1] != '#')
            {
                q.push(make_pair(i,j+1));
                print_board(b,vis,q,c);
            }
        }
    }
}

void print_board(Board& b)
{
    int n = b.   size();
    int m = b[0].size();

    Visited vis(n,vector<bool>(m,false));

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j) 
        {
            if(not vis[i][j] and b[i][j] != '#')
            {
                stack<pair<int,int>> q;
                char c = ' ';
                q.push(make_pair(i,j));
                print_board(b,vis,q,c);
                if(c != ' ')
                {
                    while(!q.empty())
                    {
                        b[q.top().first][q.top().second] = c;
                        q.pop();
                    }
                }
            } 
        }
    }
}

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        Board b(n,vector<char>(m));
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j) cin >> b[i][j];
        }
        print_board(b);
        for(vector<char> row: b)
        {
            for(char x : row) cout << x;
            cout << endl;
        }
        cout << endl;
    }
}