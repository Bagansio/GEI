#include <iostream>
using namespace std;

void digitos(int n,int& suma){
    if(n / 10 == 0){
        cout << n % 10;
        suma += n % 10;
    }
    else {
        digitos(n/10,suma);
        suma += n % 10;
        cout << " + " << n % 10;
    }
}


int main(){
    int n;
    while (cin >> n and n >= 0){
        int suma = 0;
        digitos(n,suma);
        cout << " = " << suma << endl;
    }
}