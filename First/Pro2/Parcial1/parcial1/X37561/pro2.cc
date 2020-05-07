#include <iostream>
#include "Cjt_estudiants.hh"
#include "solution.hh"
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i=0; i<n; ++i) {
    Cjt_estudiants c1, c2, c3;
    double x,y,z;
    c1.llegir();
    c2.llegir();
    cin >> x >> y >> z;
    extreure_reavaluables(c1,c2,x,y,z,c3);
    cout << "Reavaluables:" << endl;
    c3.escriure();
    cout << endl;
  }
}

