#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
{
    b = false;
    int dni = est.consultar_DNI();
    int i = cerca_dicot(vest,0,nest-1,dni);
    if (dni == vest[i].consultar_DNI())
    {
        b = true;
    }
    else
    {
        for (int j = nest; j > i; --j)
        {
            vest[j] = vest[j-1];
        }
        vest[i] = est;
        ++nest;
        recalcular_posicio_imax();
    }
}

void Cjt_estudiants::eliminar_estudiants_sense_nota()
{
    int del_est = 0;
    for (int i = 0; i < nest; ++i)
    {
        if (not vest[i].te_nota())
        {
            ++del_est;
        }
        else 
        {
            vest[i - del_est] = vest[i];
        }
    }
    nest -= del_est;
    recalcular_posicio_imax();
}