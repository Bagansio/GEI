#include "LlistaIOEstudiant.hh"

int main()
{
    list<Estudiant> l;
    LlegirLlistaEstudiant(l);
    int dni, c = 0;
    cin >> dni;
    list<Estudiant>::iterator  itfinal = l.end();
    for(list<Estudiant>::iterator it = l.begin(); it != itfinal; ++it)
    {
        if ((*it).consultar_DNI() == dni) ++c;
    }
    cout << dni << ' ' << c << endl;
}