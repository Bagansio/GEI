#include <iostream>
#include <vector>
using namespace std;


vector<double> diferencia(const vector<double> & V1, const vector<double> & V2){
  vector<double> V(0);
  int n1 = V1.size();
  int n2 = V2.size();
  int i = 0;
  int j = 0;
  while (i < n1 and j < n2){
    if (V1[i] < V2[j]){
      if(V1[i] < V2[j] and (i == 0 or V1[i - 1] != V1[i])) V.push_back (V1[i]);
      ++i;
    }
    else if(V2[j] < V1[i]){
      ++j;
    }
    else ++i;
  }
  while (i < n1){
      if(i == 0 or V[i-1] != V1[i]) V.push_back (V1[i]);
      ++i;
    }
  return V;
}

int main(){
    int n;
    cin >> n;
    vector<double> v1(n);
    for (int i = 0; i < n; ++i) cin >> v1[i];

    int k;
    cin >> k;
    vector<double> v2(k);
    for (int i = 0; i < k; ++i) cin >> v2[i];

    vector<double> dif;
    dif = diferencia(v1,v2);

    for (int i = 0; i < dif.size(); ++i) {
        if (i > 0) cout << ' ';
        cout << dif[i];
    }
}
