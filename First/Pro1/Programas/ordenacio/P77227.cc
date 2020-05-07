#include <iostream>
#include <vector>
using namespace std;


string sortida(int p, vector<int>& v){
  int n = v.size();
  vector<bool> aux(n,false);
  while(not aux[p]){
    aux[p] = true;
    if (v[p] > 0){
      if(v[p] >= n - p) return "dreta";
      p += v[p];
    }
    else if (v[p] < 0){
      if(p + v[p] < 0) return "esquerra";
      p += v[p];
    }
  }
    return "mai";
}

//
// int main() {
//   int p, n;
//   while (cin >> p >> n) {
//     vector<int> v(n);
//     for (int i = 0; i < n; ++i) cin >> v[i];
//     cout << sortida(p, v) << endl;
//   }
// }
