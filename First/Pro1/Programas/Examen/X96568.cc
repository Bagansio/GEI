#include <iostream>
using namespace std;

// Pre: x>0
int product_of_consecutive(int x){
    int left = 0;
    int right = x+1;
    while (right >= left){
        int mid = (right - left)/2 + left;
        if (mid * (mid + 1) == x) return mid; //igual
        else if(mid * (mid +1) > x) right = mid - 1; //+gran
        else left = mid + 1; //+petit
    }
    return -1;
}

int main() {
   int x;
   while (cin >> x) {
      int k = product_of_consecutive(x);
      if (k == -1) cout << x << " NO" << endl;
      else cout << x << " = " << k << "*" << k+1 << endl;
   }
}