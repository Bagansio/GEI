#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > Matriu;

int suma_linia(const Matriu& mat, int of, int oc, int df, int dc){
  int dx = df - of;
  int dy = dc - oc;
  int s = 0;
  if (dx + dy > 0){
    for (int i = 1; i <= dx + dy; ++i){
      if(dx == 0) s += mat[of][oc + i];
      else s += mat[of + i][oc];
    }
  }
  else {
    for (int i = -1; i >= dx + dy; --i){
      if(dx == 0) s += mat[of][oc + i];
      else s += mat[of + i][oc];
    }
  }
 return s;
}

int main(){
  int n,m;
  cin >> n >> m;
  Matriu A (n, vector <int> (m));
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      cin >> A[i][j];
    }
  }
  int x;
  cin >> x;
  int y;
  cin >> y;
  int s = A[x][y];
  int auxy,auxx;
  auxx = x;
  auxy = y;
  while (cin >> x >> y){
    s += suma_linia(A,auxx,auxy,x,y);
    auxx = x;
    auxy = y;
  }
  cout << "suma = " << s << endl;
}
