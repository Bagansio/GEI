#include <iostream>
#include <vector>
using namespace std;

bool ciclic(const vector<vector<int>>& graph, vector<bool>& vis,int i)
{
    int n = graph.size();
    if(i == n) return false;
    if(vis[i]) return true;
    vis[i] = true;
    for(auto v : graph[i])
    {
        if(ciclic(graph,vis,v)) return true;
    }
    vis[i] = false;
    return false;
}

bool ciclic(const vector<vector<int>>& graph)
{
    int n = graph.size();
    vector<int> indeg(n,0);
    for(int u = 0; u < n; ++u)
        for(int v : graph[u]) ++indeg[v];
    
    vector<int> cands;
    for (int u = 0; u < n; ++u)
        if (indeg[u] == 0)
            cands.push_back(u);

    while(not cands.empty())
    {
        int u = cands.back();
        cands.pop_back();
        --n;
        for(int v : graph[u])
        {
            --indeg[v];
            if(indeg[v] == 0) cands.push_back(v);
        }

    }
    return n > 0;
    /*
    vector<bool> vis(graph.size(),false);
    return ciclic(graph,vis,0);*/
}

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        vector<vector<int>> graph(n);
        for(int i = 0; i < m; ++i)
        {
            int u,v;
            cin >> u >> v;
            graph[u].push_back(v);
        }
        if(ciclic(graph)) cout << "yes";
        else cout << "no";
        cout << endl;
    }
}