#include <iostream>
using namespace std;
//P32046

int main() {

    int a,b;

    cin >> a;

    int cont = 0;

    cout << "nombres que acaben igual que " << a << ':' << endl;

    while (cin >> b) {

        if ((b-a)%1000 == 0) {

                ++cont;
                cout << b << endl;
        }
    }
    cout << "total: " << cont << endl;

}
