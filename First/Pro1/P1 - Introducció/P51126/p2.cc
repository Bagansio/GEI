#include <iostream>
using namespace std;

int main(){
    int i1,f1,i2,f2;
    int i3;
    int f3;


    cin >> i1 >> f1 >> i2 >> f2;


    if (i1<=i2){
        i3=i2;
    }
    else {i3=i1;}

    if (f2<=f1){
        f3=f2;
    }
    else {f3=f1;}

    if (f1 < i2 or f2 < i1){
        cout << "[]" << endl;
    }
    else
    cout << "[" << i3 << "," << f3 << "]" << endl;
}
