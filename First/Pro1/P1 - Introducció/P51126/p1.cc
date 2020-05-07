#include <iostream>
using namespace std;

int main() {
    int a1,b1,a2,b2,a3,b3;
    cin>> a1>> b1>> a2>> b2;

    if (a2>=a1) {
        a3=a2;
    }
    else {a3=a1;}

    if (b1>=b2) {
        b3=b2;
    }
    else {b3=b1;}

    if (b1<a2 or b2<a1) {
        cout << "[]"<< endl;
    }
    else {
    cout<< "["<<a3<< ","<< b3<< "]"<< endl;
    }
}
