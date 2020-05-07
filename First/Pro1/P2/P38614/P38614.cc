//P38614

#include <iostream>
using namespace std;

int main () {

    int n,p,s,i;
    p = 0, s = 0, i = 1;
    cin >> n;
    while (n-i >= -10) {
            i *= 10;
            p++;
            if (p%2 == 1) (s += (((n%i)-(n%(i/10)))/(i/10)));

    }
    if (s%2 == 0) cout << n << " ES TXATXI" << endl;
    else cout << n << " NO ES TXATXI" << endl;
}


