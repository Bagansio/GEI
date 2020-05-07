#include <iostream>
#include <vector>
using namespace std;


int position_maximum(const vector<double>& v, int m){
  int max = 0;
  for (int i = 0; i <= m; ++i){
    if (v[m] > v[max]) max = m;
    else if (v[m] == v[max] and m < max) max = m;
    if (v[i] > v[max]) max = i;
    --m;
  }
  return max;
}


int main() {
  int m, n;
  while (cin >> m >> n) {
    vector<double> V(n);
    for (int i = 0; i < n; ++i) cin >> V[i];
    cout << position_maximum(V, m) << endl;
  }
}
