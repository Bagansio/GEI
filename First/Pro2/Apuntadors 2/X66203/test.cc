#include "ArbNIOint.hh"

int main()
{
    ArbreNari<int> a(3);
    llegir_arbre_int(a,0);
    escriure_arbre_int(a);
    cout << "---------------" << endl;
    cout << a.maxim() << endl;
}