#include "LlistaIOParInt.hh"

void LlegirLlistaParInt(list<ParInt>& l)
{
    ParInt aux;
	while (aux.llegir() and not (aux.primer() == 0 and aux.segon() == 0))
    {
		l.push_back(aux);
	}
}

void EscriureLlistaParInt(const list<ParInt>& l)
{
	for (list<ParInt>::const_iterator it = l.begin(); it != l.end(); ++it) (*it).escriure();
}
