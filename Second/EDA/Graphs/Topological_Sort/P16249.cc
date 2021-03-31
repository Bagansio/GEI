#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;


void topological_sort(map<int,string>& str,map<string,int>& num, const vector<vector<int>> & G,vector<int>& apuntat)
{
    priority_queue <string,vector<string>, greater<string>> PQ;
    
    int n = G.size();
    map <string,int>::const_iterator it = num.begin();
    while(it != num.end())
    {
        if(apuntat[it->second] == 0) PQ.push(it->first);
        ++it;
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
    

    if(aux.size() != n) cout << "NO VALID ORDERING" << endl;
    else
    {
        while(not aux.empty())
        {
            cout << aux.front();
            aux.pop();
        }
        cout << endl;
    }
    
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
        vector<vector<int>> G(n);
        vector<int> apuntat(n,0);
        for(int i = 0; i < m; ++i)
        {
            string a,b;
            cin >> a >> b;
            G[num[a]].push_back(num[b]);
            ++apuntat[num[b]];
        }

        topological_sort(str,num,G,apuntat);
    }
}