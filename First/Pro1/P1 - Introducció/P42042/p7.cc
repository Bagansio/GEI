#include <iostream>
using namespace std;

int main() {
    char letra;
    cin>> letra;
    if (int(letra)>=int('a')) {
        cout<< "minuscula";
        if (letra == 'a' or letra == 'e' or letra == 'i' or letra == 'o' or letra == 'u'){
        cout<< "\n"<< "vocal"<< endl;
        }
        else {
            cout<< "\n"<< "consonant"<< endl;
            }
        }
    else {
        cout<< "majuscula";
        if (letra == 'A' or letra == 'E' or letra == 'I' or letra == 'O' or letra == 'U'){
        cout<< "\n"<< "vocal"<< endl;
        }
        else {
            cout<< "\n"<< "consonant"<< endl;
        }
    }
}

