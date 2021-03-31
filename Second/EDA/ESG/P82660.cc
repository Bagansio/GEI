#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool comp(int a, int b)
{
    return a > b;
}

bool generate(const vector<int>& numbers,vector<int>& solution,int i , int partial_sum,int s)
{
    if(i < numbers.size())
    {
        solution.push_back(numbers[i]);
        if(generate(numbers,solution,i+1,partial_sum+numbers[i],s)) return true; 
        solution.pop_back();
        if(generate(numbers,solution,i+1,partial_sum,s)) return true;
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
        return true;
    }
    return false;
}

int main()
{
    int s,n;
    cin >> s >> n;
    vector<int> numbers(n);
    for(int& i : numbers) cin >> i;
    sort(numbers.begin(),numbers.end(),comp);
    vector<int> solution;
    if(not generate(numbers,solution,0,0,s)) cout << "no solution" << endl;
}