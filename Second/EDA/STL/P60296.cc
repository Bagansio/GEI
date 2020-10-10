#include <map>
#include <iostream>
#include <set>
using namespace std;

struct compare
{
    bool operator()(const pair<string,int>& a, const pair<string,int>& b)
    {
        if (a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    }
};

int main ()
{
    map<string,pair<int,bool>> players;

    string c;
    while (cin >> c)
    {
        string p1;
        cin >> p1;
        auto found = players.find(p1);
        if (c == "LOGIN")
        {
            if (found != players.end()) found->second.second = true;
            else players[p1] = make_pair(1200,true);
        }
        else if (c == "LOGOUT" and found != players.end())
        {
            found->second.second = false;
        }
        else if (c == "PLAY")
        {
            string p2;
            cin >> p2;

            if (found != players.end() and players.find(p2) != players.end() and (players[p1].second and players[p2].second))
            {
                found->second.first += 10;
                if (players[p2].first > 1200) players[p2].first -= 10;
            }
            else cout << "player(s) not connected" << endl;
        }
        else if (c == "GET_ELO")
        {
            if (found != players.end())
            {
                cout << p1 << ' ' << players[p1].first << endl;
            }
        }
    }
    cout << endl << "RANKING" << endl;

    set<pair<string,int>, compare> S;
    for (pair <string, pair <int,bool>> p : players) S.insert(make_pair(p.first,p.second.first));
    for (pair <string,int> p : S) cout << p.first << ' ' << p.second << endl;
}