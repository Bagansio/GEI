#include <iostream>
#include <map>
#include <vector>
using namespace std;


void generate(map<string,int>& col,const vector<string> & new_col, int i, int games)
{
    int n = new_col.size();
    if(i < n)
    {
        string aux = new_col[i];
        bool added = true;
        if(col.find(aux) == col.end()) col[aux] = 1;
        else if((games+1)/2 > col[aux])
        {
            ++col[aux];
        }
        else 
        {
            generate(col,new_col,i+1,games);
            added = false;
        }
        if (added) generate(col,new_col,i+1,games+1);
    }
}



int main()
{
    int n;
    while(cin >> n)
    {
        map<string,int> col;
        for(int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            if(col.find(s) == col.end()) col[s] = 1;
            else ++col[s];
        }
        int j; cin >> j;
        vector<string> new_col(j);
        for(string& s : new_col) cin >> s;
        //map<string,int> new_col = load_colection(n) 
        generate(col,new_col,0,n);
        for(pair<string,int> game : col) cout << game.first << ' ' << game.second << endl;
        cout << "--------------------" << endl;
    }
}