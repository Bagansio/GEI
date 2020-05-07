#include "LlistaIOEstudiant.hh"

void LlegirLlistaEstudiant(list<Estudiant>& l)
{
    Estudiant x;
    x.llegir();
    while ((x.consultar_DNI() != 0))
    {
        l.push_back(x);
        x.llegir();
    }
}

void EscriureLlistaEstudiant(list<Estudiant>& l)
{
    list<Estudiant>::iterator  itfinal = l.end();
    for(list<Estudiant>::iterator it = l.begin(); it != itfinal; ++it)
    {
        (*it).escriure();
    }
}