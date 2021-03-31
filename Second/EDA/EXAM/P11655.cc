#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& sol)
{
    bool first = true;
    for(int i : sol)
    {
        if(first) 
        {
            first = false;
            cout << '{';
        }
        else cout << ',';
        cout << sol[i];
    }
    cout << '}' << endl;
}

void generate(const vector<int>& numbers,vector<int>& solution,int i , int partial_sum,int s,int ps)
{
    if(partial_sum + ps >= s and partial_sum <= s and i < numbers.size())
    {
        generate(numbers,solution,i+1,partial_sum,s,ps-numbers[i]);
        solution.push_back(numbers[i]);
        generate(numbers,solution,i+1,partial_sum+numbers[i],s,ps-numbers[i]); 
        solution.pop_back();
    }
    else if(s == partial_sum) //draw
    {
        bool first = true;
        cout << '{';
        for(int j : solution) 
        {
            if(not first) cout << ',';
            else  first = false;
            cout << j;
        }
        cout << '}' << endl;
    }
}



int main()
{
    int s,n;
    cin >> s >> n;
    vector<int> set(n);
    int sum = 0;
    for(int& i : set) 
    {
        
        cin >> i;
        sum += i;
    }
    vector<int> sol;
    generate(set,sol,0,0,s,sum);
}