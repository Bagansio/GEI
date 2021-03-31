#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

const int oo = INT_MAX;

#define P pair<int,int>
#define PP pair<P,int>

P djk(const vector<vector<P>>& g, int a, int b)
{
    int n = g.size();
    vector<P> dist(n, {+oo,+oo});
    priority_queue <PP, vector<PP>, greater<PP>> pq;
    dist[a] = {0,0};
    pq.push({{0,a},0});
    while(not pq.empty())
    {
        
        int d = pq.top().first.first;
        int u = pq.top().first.second;
        int ps = pq.top().second;
        pq.pop();
        if(d == dist[u].first)
        {
            if(u == b) return dist[b];
            for(auto e : g[u])
            {
                int w = e.first;
                int v = e.second;

                int dv = dist[u].first + w;
                
                if(dist[v].first > dv or (dist[v].first == dv and ps+1 < dist[v].second))
                {
                    dist[v].first = dv;
                    dist[v].second = ps+1;
                    pq.push({{dv,v},ps+1});
                }

            }
        }

    }
    return {+oo,0};
}

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        vector<vector<P>> g(n);
        for(int i = 0; i < m; ++i)
        {
            int u,v,c;
            cin >> u >> v >> c;
            g[u].push_back({v,c});
            g[v].push_back({u,c});
        }
        int a,b;
        cin >> a >> b;
        P p = djk(g,a,b);
        if(p.first == +oo) cout << "no path from " << a << " to " << b;
        else cout << "cost " << p.first << ", " << p.second << " step(s)";
        cout << endl;   
    }
}