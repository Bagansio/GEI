#include "CuaIOint.hh"

int main()
{
    Cua <int> a;
    llegir_cua_int(a,0);
    Cua <int> b;
    llegir_cua_int(b,0);
    a.concat(b);
    escriure_cua_int(a);
}