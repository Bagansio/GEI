#include <iostream>
#include <vector>
using namespace std;


void insert(vector<double>& v){
  int n = v.size();
  for(int i = 0; i < 2; ++i){
    double x = v[n - 2 + i];
    int j = n - 2 + i;
    while(j > 0 and v[j - 1] > x){
      v[j] = v[j - 1];
      --j;
    }
    v[j] = x;
  }
}

//
// int main() {
//     cout.setf(ios::fixed, ios::floatfield);
//     cout.precision(4);
//     int n;
//     while (cin >> n) {
//         vector<double> V(n);
//         for (int i=0; i<n; ++i) {
//             cin >> V[i];
//         }
//         insert(V);
//         for (int i=0; i<n; ++i) {
//             cout << " " << V[i];
//         }
//         cout << endl;
//     }
// }
