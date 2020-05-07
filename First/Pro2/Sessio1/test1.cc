#include "X49116.cc"
#include <iostream>
#include <vector>
using namespace std;

  /** @brief Base class for Debug Mode vector.
   *
   * Adds information about the guaranteed capacity, which is useful for
   * detecting code which relies on non-portable implementation details of
   * the libstdc++ reallocation policy.
   */
int main(){
    int n;
    cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    int max,min;
    max_min3(v,max,min);
    cout << max << ' ' << min << endl;
    pair <int,int> a = max_min2(v);
    cout << a.first << ' ' << a.second << endl;
    parint p = max_min1(v);
    cout << p.prim << ' ' << p.seg << endl; 
}
