#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int>> Matrix;

void mult(const Matrix& m1, const Matrix& m2, Matrix& n, int mod)
{
    n = Matrix(2,vector<int> (2,0));
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            for(int k = 0; k < 2; ++k)
            {
                n[i][j] += m1[i][k] * m2[k][j];
            }
            n[i][j] %= mod;
        }
    }
}

void powM(const Matrix& m, int mod, int p, Matrix& n)
{
    if (p == 0)
    {
        n[0][0] = n[1][1] = 1;
        n[0][1] = n[1][0] = 0;
    }
    else if (p == 1)
    {
        n[0][0] = m[0][0] % mod;
        n[0][1] = m[0][1] % mod;
        n[1][0] = m[1][0] % mod;
        n[1][1] = m[1][1] % mod;
    }
    else if (p % 2 == 0)
    {
        Matrix aux(2,vector<int> (2));
        powM(m,mod,p/2,aux);
        mult(aux,aux,n,mod);
    }
    else
    {
        Matrix aux(2,vector<int> (2));
        powM(m,mod,p-1,aux);
        mult(m,aux,n,mod);
    }
}

int main()
{
    Matrix m(2,vector<int> (2));
    int p,mod;
    while(cin >> m[0][0] >> m[0][1] >> m[1][0] >> m[1][1] >> p >> mod)
    {
        Matrix n(2,vector<int> (2));
        powM(m,mod,p,n);
        cout << n[0][0] << ' ' << n[0][1] << endl << n[1][0] << ' ' << n[1][1] << endl << "----------" << endl;
    }
}