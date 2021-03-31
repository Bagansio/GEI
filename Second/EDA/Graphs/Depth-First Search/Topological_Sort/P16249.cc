#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;


void topological_sort(map<int,string>& str,map<string,int>& num, const vector<vector<int>> & G)
{
    priority_queue <string,vector<string>, greater<string>> PQ;
    
    int n = G.size();
    vector<int> apuntat(n,0);
    for(int i = 0; i < n; ++i)
        for(int j : G[i])
        {
            PQ.push(str[j]);
            ++apuntat[j];
        }
    
    queue<string> aux;
    while(not PQ.empty())
    {
        string u = PQ.top(); PQ.pop();
        aux.push(u);
        for(int v: G[num[u]])
        {
            if(--apuntat[v] == 0) PQ.push(str[v]);
        }
    }

    if(aux.size() != n) cout << "NO VALID ORDERING";
    else
    {
        while(not aux.empty())
        {
            cout << aux.front();
            aux.pop();
        }
    }
    cout << endl;
}

int main()
{
    int n;
    while(cin >> n) 
    {
        //vector<string> tasks(n);
        map<string,int> num;
        map<int,string> str;
        for(int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            num.insert({s,i});
            str.insert({i,s});
        }
        int m;
        cin >> m;
        vector<vector<int>> G(m);

        for(int i = 0; i < m; ++i)
        {
            pair<string,string> p;
            cin >> p.first >> p.second;
            G[num[p.first]].push_back(num[p.second]);
        }

        topological_sort(str,num,G);
    }
}