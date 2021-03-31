#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void count(const vector<int> coins, vector<pair<bool,bool>>& used_coins, int i, int partial_sum, int total_sum)
{
    
    if(partial_sum == total_sum) //print solution
    {
        cout << total_sum << " = ";
        bool first = true;
        int n = coins.size();
        for(int j = 0; j < n; ++j)
        {
            if(used_coins[j].first)
            {
                if(first)
                {
                    first = false;
                    cout << coins[j];
                }
                else  cout << " + " << coins[j];
            }
            if(used_coins[j].second)
            {
                if(first)
                {
                    first = false;
                    cout << coins[j] << 'p';
                }
                else cout << " + " << coins[j] << 'p';
            }
       }
        cout << endl;
    }
    else if(i < coins.size() and partial_sum < total_sum)
    {
        if(coins[i] + partial_sum <= total_sum)
        {
            used_coins[i] = {true,true};
            count(coins,used_coins,i+1,partial_sum+(2*coins[i]),total_sum);
            used_coins[i] = {true,false};
            count(coins,used_coins,i+1,partial_sum+coins[i],total_sum);
            used_coins[i] = {false,true};
            count(coins,used_coins,i+1,partial_sum+coins[i],total_sum);
            used_coins[i] = {false,false};
            count(coins,used_coins,i+1,partial_sum,total_sum);
        }
    }
}

int main()
{
    int x,n;
    while(cin >> x >> n)
    {
        vector<int> coins(n);
        for(int& i : coins) cin >> i;
        sort(coins.begin(),coins.end());
        vector<pair<bool,bool>> used_coins(n,{false,false});
        count(coins,used_coins,0,0,x);
        cout << "----------" << endl;   
    }
}