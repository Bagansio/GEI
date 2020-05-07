#include <iostream>
using namespace std;

int main() {
    char letra;
    cin>> letra;
    if (int(letra)>=int('a')) {
        cout<< "minuscula";
    }
    else {
        cout<< "majuscula";
    }
    if (letra=='a'){
        cout<< "vocal";
    }
    else {
        if (letra=='e') {
            cout<< "vocal";
        }
        else {
            if (letra=='i') {
                cout<< "vocal";
            }
            else {
                if (letra=='o') {
                cout<< "vocal";
                {
                else {
                cout<< "consonant";
                }
                }
        }
    }
        }
    }
    cout<< endl;
        }
