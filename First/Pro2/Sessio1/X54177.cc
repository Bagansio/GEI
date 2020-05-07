#include <iostream>
using namespace std;

int main(){
    int x,zero; //numero de secuencias
    string s;
    cin >> x >> zero;
    for (int i = 1; i <= x; ++i){
        int n;
        int suma = 0;
        while (cin >> n){
            if (n == zero){
                getline(cin,s);
                break;
            }
            else suma += n;
        }
        cout << "La suma de la secuencia " << i << " es " << suma << endl;
    }
}