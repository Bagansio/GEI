#include <iostream>
using namespace std;

//tenim un tauler, de f*c i volem sumar els espais en blanc
int main(){
    int f,c;
    cin >> f >> c;

    int i = 0, sum = 0, p_columna = 0;
    int p_fila;
    char moneda;
    while (i < f*c) {

        p_fila = p_columna;
        while (p_fila < f) {
            cin >> moneda;
            if (p_fila%2 == 0) sum += int(moneda);
            ++p_fila;
            ++i;
        }

        ++p_columna;

    }
    cout << sum << endl;
}
