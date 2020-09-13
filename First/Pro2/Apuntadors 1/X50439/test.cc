#include "PilaIOint.hh"

int main()
{
    Pila <int> a,b;
    llegir_pila_int(a,0);
    llegir_pila_int(b,0);
    a.operator=(b);
    escriure_pila_int(a);
}