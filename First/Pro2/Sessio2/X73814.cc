#include "Estudiant.hh"
#include <vector>
#include <iostream>
using namespace std;

void write(const vector<Estudiant>& v)
{
    int n = v.size();
    for(int i = 0; i < n; ++i)
    {
        v[i].escriure();
    }
}

Estudiant nota_alta(const vector<Estudiant>& v, int dni)
{
    int n = v.size();
    Estudiant aux(dni);
    for (int i = 0; i < n; ++i)
    {
        if (v[i].consultar_DNI() == dni)
        {
            if(v[i].te_nota())
            {
                if (aux.te_nota())
                {
                   if (aux.consultar_nota() < v[i].consultar_nota()) aux.modificar_nota(v[i].consultar_nota());
                
                }
                else aux.afegir_nota(v[i].consultar_nota()); 
            }
        }
    }
    return aux;
}

vector<Estudiant> simplificar(const vector<Estudiant>& v)
{
    int n = v.size();
    vector<Estudiant> aux;
    for (int i = 0; i < n; ++i)
    {
        int j = 0;
        int p = aux.size();
        while (j < p and v[i].consultar_DNI() != aux[j].consultar_DNI())
        {
            ++j;
        }
        if(j == p or p == 0) aux.push_back(nota_alta(v,v[i].consultar_DNI()));
        ++i;
    }
    
     return aux;
}


vector<Estudiant> read()
{
    int n;
    cin >> n;
    vector<Estudiant> v(n);
    for(int i = 0; i < n; ++i)
    {
        v[i].llegir(); 
    }
    return v;
}

int main()
{
    vector<Estudiant> v = read();
    write(simplificar(v));
}