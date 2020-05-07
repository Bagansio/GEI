#include <iostream>
#include <vector>
using namespace std;

bool quadrat_magic (const vector< vector<int> >& M){
  int n = M.size();
  int comp = 0;
  int aux = 0;
  for (int i = 0; i < n; ++i){
    comp += M[i][i];
    aux += M[i][n - i - 1];
  }
  if (aux != comp) return false;
  for (int i = 0; i < n; ++i){
    aux = 0;
    int aux1 = 0;
    for (int j = 0; j < n; ++j){
      aux += M[i][j];
      aux1 += M[j][i];
    }
    if (aux != comp or aux1 != comp) return false;
  }
   for (int k = 1; k <= n*n; ++k){
     bool trobat = false;
     int i = 0;
     while (i < n and not trobat){
       int j = 0;
       while (j < n and not trobat){
         if(not trobat and M[i][j] == k) trobat = true;
         ++j;
       }
       ++i;
     }
     if(not trobat) return false;
   }
  return true;
}


int main ()
{
    int n;
    while (cin >> n) {
        vector< vector<int> > M(n, vector<int>(n));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                cin >> M[i][j];
        }   }
        cout << quadrat_magic(M) << endl;
}   }
