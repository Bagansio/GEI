#include "ArbIOint.hh"

int main()
{
    int x;
    cin >> x;
    Arbre<int> a;
    llegir_arbre_int(a, 0);
    cout << endl;
    escriure_arbre_int(a);
    cout << endl;
    Arbre<int> suma;
    a.sub_arrel(suma,x);
    escriure_arbre_int(suma);
    cout << endl;
}