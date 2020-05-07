#include <queue> 
#include <iostream>
using namespace std;

void actualitzar(int& max, int& min,queue <int> cua)
{
    max = -1000, min = 1000;
    while (not cua.empty())
    {
        int n = cua.front();
        if (n > max) max = n;
        if (n < min) min = n;
        cua.pop();
    }
}

int main(){
    int n,min,max;
    min = 1000;
    max = -1001;
    double sum = 0;
    queue <int> cua;
    while(cin >> n and n >= -1001 and n < 1001)
    {
        if (n != -1001)
        {
            cua.push(n);
            sum += n;
            if (n > max) max = n;
            if (n < min) min = n; 
        }
        else if (not cua.empty())
        {
            n = cua.front();
            cua.pop();
            if (max == n or min == n) actualitzar(max,min,cua);
            sum -= n;
        }
        if (cua.empty())
        {
            cout << '0';
            max = -1000, min = 1000;
        }
        else cout << "min " << min <<"; max " << max << "; media " << (sum/cua.size());
        cout << endl;
    }
}