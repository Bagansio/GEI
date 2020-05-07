#include <iostream>
using namespace std;

int main () {

    int n,d;

    cin >> n ;

    while (n/2 != 0) {

        d = n%2;
        cout << d ;
        n /=2;

    }
    cout << n%2 << endl;
}
