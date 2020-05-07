#include <iostream>
using namespace std;
// P27341
int main() {

    int a,b,suma,i;

    while (cin >> a >> b) {

    i = a;
    suma = 0;

        while (i <= b) {

        suma += i*i*i;

        ++i;

        }

    cout << "suma dels cubs entre " << a << " i " << b << ": " << suma << endl;

    }
}

