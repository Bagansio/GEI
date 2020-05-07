#include <iostream>
using namespace std;

int main () {
     cout.setf(ios::fixed);
     cout.precision(4);

    double c,i,res;
    int t,a;
    string interes;
    a=0;
    cin >> c >> i >> t >> interes ;
    res = (1+(i/100));
    if (interes == "simple") {

        cout << c+c/100*i*t << endl;
    }
    else {
            while (a==t) {
                res = (res * (1+(i/100)));
                cout << res << "hi";
                a = a +1;
            }

        cout << (c*res) << endl;
        }
    }




