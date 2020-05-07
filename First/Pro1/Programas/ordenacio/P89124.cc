#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000;

vector<bool> garbell(int n){
  vector<bool> aux(n+1, true);
  for (int i = 2; i <= n; ++i){
    for (int j = 2*i; j <= n; j += i){
      aux[j] = false;
    }
  }
  return aux;
}

int main(){
  int n;
  vector<bool> auxiliar;
  auxiliar = garbell(MAX);
  while(cin>>n) {
  if (n == 0 or n == 1) cout << n << " no es primer";
  else {
    if (auxiliar[n]) cout << n << " es primer";
    else cout << n << " no es primer";
  }
  cout << endl;
  }
}
