#include <iostream>
using namespace std;

int  main()
{
    short a = 0x6543;
    short b = -16;
    short c,d,e;
    c = a / b;
    d = a % b;
    e = a >> 4;

    cout << c << ' ' << d << ' ' << e << ' ' << endl;
}