#include "ArbIOint.hh"

int main()
{
    Arbre<int> a;
    llegir_arbre_int(a, 0);
    cout << endl;
    escriure_arbre_int(a);
    cout << endl;
    Arbre<int> suma;
    a.arb_sumes(suma);
    escriure_arbre_int(suma);
    cout << endl;
}