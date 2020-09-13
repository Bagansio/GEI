#include "LlistaIOint.hh"

int main()
{
    Llista<int> l;
    llegir_llista_int(l,0);
    escriure_llista_int(l);
    l.reorganitzar_in(9);
    escriure_llista_int(l);
}