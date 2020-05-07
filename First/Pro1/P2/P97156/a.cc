#include <iostream>
using namespace std;

int main() {

    int a,b;

    cin >> a >> b;

    if (a <= b) {

        cout << a ;

        while (a < b) {

            a++;

            cout << ',' << a ;

        }
    }
    cout << endl;
}
