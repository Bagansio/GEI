#include "CuaIOint.hh"

int main()
{
    Cua <int> a;
    llegir_cua_int(a,0);
    escriure_cua_int(a);
    Cua<int> h;
    llegir_cua_int(h,0);
    a.trenat(h);
    escriure_cua_int(a);
}