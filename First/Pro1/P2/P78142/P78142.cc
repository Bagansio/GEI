// P78142

#include <iostream>
using namespace std;

int main () {

    cout.setf(ios::fixed);
    cout.precision(2);

    double n,m;
    int c;

    m = 0, c = 0;
    while (cin >> n) {

            m += n;
            c++;
    }

    cout << m/c << endl;
}

