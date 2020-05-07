#include <iostream>
#include <math.h>
using namespace std;

int main () {

    cout.setf(ios::fixed);
    cout.precision(6);

    int n;
    double llargada, amplada, radi;
    string paraula;
    cin >> n;

    while ( n != 0) {

        cin >> paraula ;

        if (paraula == "rectangle") {

                cin >> llargada >> amplada;

                cout << llargada*amplada << endl;
        }

        else {

            cin >> radi ;

            cout << M_PI*radi*radi << endl;
        }

        n--;

    }
}
