#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
using P = pair<int,int>;
const int oo = INT_MAX;


int cost(const vector<vector<P>>& g, const vector<int>& cost_nit, int a, int b)
{
    int n = g.size();
    vector<double> dist(n,+oo);
    priority_queue <P, vector<P>, greater<P>> pq;
    dist[a] = 0;
    pq.push({0,a});
    while(not pq.empty())
    {
        auto t = pq.top();
        pq.pop();
        int d = t.first;
        int u = t.second;
        if(d == dist[u])
        {
            if(u == b) return dist[b];
            for(auto e : g[u])
            {
                int v = e.first;
                int w = e.second;
                //int dv = dist [u] + w + (v == b ? 0 : cost_nit[v ]);
                
                int dv = dist[u] + w;
                if(v != b) dv += cost_nit[v];
                if(dist[v] > dv)
                {
                    dist[v] = dv;
                    pq.push({dv,v});
                } 
            }
        }
    }
    return +oo;
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> cost_nit(n);
    for(int& i : cost_nit) cin >> i;
    vector<vector<P>> g(n);
    while(m--)
    {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    int a,b;
    while(cin >> a >> b)
    {
        int c = cost(g,cost_nit,a,b);
        cout << "c(" << a << ',' << b << ") = ";
        if(c == +oo) cout << "+oo" << endl;
        else         cout << c << endl;
    }
}