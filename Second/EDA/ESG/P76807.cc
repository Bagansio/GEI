#include <iostream>
#include <vector>

using namespace std;

using VE = vector<int>;
using VVE = vector<VE>;
using VVVE = vector<VVE>;

int main()
{
    int n;
    cin >> n;
    cout << n << endl;
    while(n--)
    {
        cout << endl;
        VVE grid(9,VE(9));
        VVE row(9, VE(10, false)); //fila a consultar
        VVE column(9, VE(10, false)); 
        VVVE quad(3,VVE(9, VE(10, false))); //quadrilatero
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j) {
                char c;
                cin >> c;
                if (c == '.') grid[i][j] = 0;
                else {
                int d = c - '0';
                grid[i][j] = d;
                row[i][d] = column[j][d] = quad[i/3][j/3][d] = true;
            }
            
        sudoku(grid,0,0);
    }
}