#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
{
    int dni = est.consultar_DNI();
    b = false;
    int i = cerca_dicot(vest, 0, nest-1, dni);
    if (vest[i].consultar_DNI() == dni) b = true;
    else
    {
        for (int j = nest; j > i; --j)
        {
            vest[j] = vest[j-1];
        }
        ++nest;
        vest[i] = est;
        if(est.te_nota())
        {
            incrementar_interval(est.consultar_nota());
        }
    }
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b)
{
    b = false;
    int i = cerca_dicot(vest, 0, nest-1, dni);
    if (vest[i].consultar_DNI() == dni)
    {
        b = true;
        if (vest[i].te_nota())
        {
        decrementar_interval(vest[i].consultar_nota());
        }
        --nest;
        for (int j = i; j < nest; ++j)
        {
            vest[j] = vest[j+1];
        }
    }
}