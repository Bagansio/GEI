#include "ArbGIOint.hh"

int main()
{
    ArbreGen<int> a;
    llegir_arbre_int(a,0);
    if(a.buscar(5)) cout << "OUU" << endl;
}