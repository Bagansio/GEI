#include <iostream>
using namespace std;

int main() {
    int celsius;
    cin>> celsius;
    if (celsius>=10) {
            if (celsius<=30){
                cout<< "s'esta be";
            }
            else {
                cout<< "fa calor";
            }
    }
    else {
            cout<< "fa fred";
        }
    if (celsius>=100){
        cout<< "\n"<< "l'aigua bulliria";
    }
    if (celsius<=0) {
        cout<< "\n"<< "l'aigua es gelaria";
    }
        cout<< endl;
    }
