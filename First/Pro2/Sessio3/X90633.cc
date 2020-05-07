#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
{
    if (nest >= MAX_NEST) throw PRO2Excepcio("Conjunt ple");
    int dni = est.consultar_DNI();
    int i = cerca_dicot(vest,0,nest-1,dni);
    b = false;
    if (vest[i].consultar_DNI() == dni) b = true;
    else
    {
        ++nest;
        for (int j = nest-1; j >= i; --j)
        {
            vest[j] = vest[j-1];
        }
        vest[i] = est;
        if (est.te_nota()) {
            suma_notes += est.consultar_nota();
            ++nest_amb_nota;
        }
    }
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b)
{
    //int i = cerca_dicot(vest,0,nest,dni);  
    int i = 0;
    b = false;
    bool exists = false;
    while (i < nest and not exists) 
    {
        if (vest[i].consultar_DNI() == dni) exists = true;
        else ++i;
    }
    if (exists)
    {
        b = true;
        if (vest[i].te_nota())
        {
            suma_notes -= vest[i].consultar_nota();
            --nest_amb_nota;
        }
        while (i < nest)
        {
            vest[i] = vest[i+1];
            ++i;
        }
        --nest;
    }
}