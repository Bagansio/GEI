#include <iostream>
using namespace std;

int main () {

    int n,d;

    cin >> n ;

    while (n/16 != 0) {

        d = n % 16;

        if (d >= 10) cout << char (int('A')+(d-10));
        else cout << d;

        n /= 16;

    }
        if ((n % 16) >= 10) cout << char (int('A')+((n % 16)-10)) << endl;
        else cout << n % 16 << endl;
}
