#include <iostream>
using namespace std;

int main() {

    int n, t, a, d, c;

    cin >> d >> n >> t;

    c = 0;

    for (int i = 1 ; i <= t ; i++) {

        cin >> a ;

        n = (n+a-d);

        if (n>0) c++;

    }
    cout << c << endl;
}
