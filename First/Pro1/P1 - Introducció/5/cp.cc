#include <iostream>
using namespace std;

int main() {
    double a;
    cin >> a;
    cout << int(a)<< " ";
    if ((int(a)-a)==0) {
    cout<< int(a)<< " ";
    }
    else {
    cout<< int(a)+1<< " ";
    }
    if ((a-int(a))>=.5) {
        cout << int(a)+1;
    }
    else {
        cout << int(a);
    }
        cout <<  endl;
}

