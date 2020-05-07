#include <iostream>
#include <vector>
using namespace std;

typedef vector < vector < char > > Matrix;

void read(Matrix& M){
  int n = M.size();
  int m = M[0].size();
  for (int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j){
      cin >> M[i][j];
    }
  }
}

int search(int x, int y, const Matrix& M){
  int n = M.size();
  int m = M[0].size();
  int c = 0;
  for (int i = -1; i < 2; ++i){
    for (int j = -1; j < 2; ++j){
      int xx,yy;
      xx = x + i;
      yy = y + j;
      if (xx >= 0 and yy >= 0 and xx < n and yy < m){
        if (M[xx][yy] == 'B' and (i != 0 or j != 0)) ++c;
      }
    }
  }
  return c;
}

void evaluate(const Matrix& M){
  int n = M.size();
  int m = M[0].size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j){
      int c = search(i,j,M);
      if((M[i][j] == 'B' and (c == 3 or c == 2)) or (M[i][j] == '.' and c == 3)){
        cout << 'B';
      }
      else cout << '.';
    }
    cout << endl;
  }
}


int main(){
  int n,m;
  bool first = true;
  while (cin >> n >> m and (n != 0 or m != 0)){
    Matrix M (n, vector <char> (m));
    read(M);
    if (not first) cout << endl;
    else first = false;
    evaluate(M);
  }
}
