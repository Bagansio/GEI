#include <iostream>
#include <vector>
using namespace std;

void generate(const vector<int>& numbers,vector<int>& solution,int i , int partial_sum,int s)
{
    if(i < numbers.size())
    {
        generate(numbers,solution,i+1,partial_sum,s);
        solution.push_back(numbers[i]);
        generate(numbers,solution,i+1,partial_sum+numbers[i],s); 
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
    vector<int> numbers(n);
    for(int& i : numbers) cin >> i;
    vector<int> solution;
    generate(numbers,solution,0,0,s);
}