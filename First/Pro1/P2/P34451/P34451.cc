#include <iostream>
//P34451
using namespace std;

int main() {

    int n1,n2;

    cin >> n1;
    int contador = 0;

    while ( cin >> n2 ) {

        if ((n2%n1) == 0) ++contador;

    }
    cout << contador << endl;
}
