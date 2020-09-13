#include "ArbGIOint.hh"

int main()
{
    ArbreGen<int> a;
    llegir_arbre_int(a,0);
    escriure_arbre_int(a);
    cout << endl << "---------" << endl << "max: " << a.max_suma_cami() << endl;
}