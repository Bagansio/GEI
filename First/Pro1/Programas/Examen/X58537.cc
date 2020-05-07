#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Row;
typedef vector<Row> Matrix;

// Pre: mat is an n*n square matrix, where n >= 2
// Post: it returns true if mat is a zero-sum tridiagonal matrix,
//       false otherwise
bool is_zerosum_tridiagonal(const Matrix& mat) {
    int n = mat.size();
    for(int i = 0; i < n - 2; ++i){
        int j = i + 2;
        while (j < n){
            if(mat[i][j] != 0 or mat[j][i] != 0) return false;
            ++j;
        }
    }
    int s1 = 0;
    int s2 = 0;
    for (int i = 0; i < n; ++i){
        s1 += mat[i][i];
        if (i+1 < n) s2 += mat[i + 1][i] + mat[i][i + 1];
    }
    return (s1 - s2 == 0);
}


Matrix read_matrix(int n) {
    Matrix m(n, Row(n));
    for (int i=0; i < n; ++i)
          for (int j = 0; j < n; ++j)
               cin >> m[i][j];
    return m;
}

int main() {
    int n;
    while (cin >> n) {
          Matrix a = read_matrix(n);
          if (is_zerosum_tridiagonal(a)) cout << "TRUE" << endl;
          else cout << "FALSE" << endl;
    }
}