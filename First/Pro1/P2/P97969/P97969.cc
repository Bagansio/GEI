#include <iostream>
using namespace std;


int main () {

    char frase;
    int contador;

    contador = 0;

    cin >> frase;
    while ('.' != frase) {

            if (frase == 'a') contador ++;

            cin >> frase;

    }
    cout << contador << endl;
}
