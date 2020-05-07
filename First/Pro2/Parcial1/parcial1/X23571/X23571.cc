#include "Cjt_estudiants.hh"

int Cjt_estudiants::posicio_nota(double nota_b) const {
    if (nota_b <= 10 and nota_b >= 0)
    {
        for(int i = primer_est_amb_nota; i < nest; ++i)
        {
            if (vest[i].consultar_nota() >= nota_b) return i;
        }
    }
    return nest;
}

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool &trobat)
{
    trobat = false;
    int dni = est.consultar_DNI();
    int i = cerca_lineal_per_dni(vest,0,nest-1,dni);
    if (vest[i].consultar_DNI() == dni)
    {
        trobat = true;
    }
    else 
    {
        i = cerca_dicot_per_nota_dni(vest,0,nest-1,est);
        if (not est.te_nota()) ++primer_est_amb_nota;
        for (int j = nest; j > i; --j)
        {
            vest[j] = vest[j-1];
        }
        ++nest;
        vest[i] = est;
    }
}

void Cjt_estudiants::escriure_i(double nota_i, double nota_s) const
{
    int i = posicio_nota(nota_i);
    while (i < nest and vest[i].consultar_nota() <= nota_s)
    {
        vest[i].escriure();
        ++i;
    }
}