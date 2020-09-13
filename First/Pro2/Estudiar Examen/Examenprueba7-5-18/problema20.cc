#include "MySet.hh"

int main()
{
    MySet <int> a;
    a.llegir();
    MySet<int> x;
    a.escriure();
    x = a.galopar();
    cout << "--------------" << endl;
    x.escriure();
}