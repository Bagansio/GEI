#include <iostream>
using namespace std;
al
int main () {

    char direccion;

    int x,y;
    x = 0 , y = 0;
    while (cin>>direccion) {
    if (direccion == 'n') y--;
    if (direccion == 's') y++;
    if (direccion == 'e') x++;
    if (direccion == 'o') x--;

    }

    cout << '(' << x << ", " << y << ')' << endl;
}
