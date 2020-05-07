#include <iostream>
using namespace std;

int main() {
    char letra;
    cin>> letra;
    if (int(letra)>=int('a')) {
    cout<<char((int(letra)-int('a'))+int('A'));
    }
    else {
    cout<<char((int(letra)-int('A'))+int('a'));
    }
    cout<<endl;
}
