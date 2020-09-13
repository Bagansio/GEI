#include "LlistaIOint.hh"

int main()
{
    Llista<int> a;
    llegir_llista_int(a,0);
    Llista<int> b;
    llegir_llista_int(b,0);
    escriure_llista_int(a);
    cout << "--------------" << endl;
    escriure_llista_int(b);
    cout << endl << endl << endl;
    a = b;
    escriure_llista_int(a);
}