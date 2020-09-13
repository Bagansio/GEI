#include "ArbNIOint.hh"

int main()
{
    ArbreNari<int> a(3);
    llegir_arbre_int(a,0);
    escriure_arbre_int(a);
    ArbreNari<int> sum(3);
    a.arbsuma(sum);
    escriure_arbre_int(sum);
}