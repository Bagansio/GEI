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

void simplificar_vector(vector<Estudiant>& v, int& pos)
/* Pre: v=V, v.size() > 0 i les notes d'un mateix estudiant son consecutives */
/* Post: pos+1 es el nombre d estudiants diferents de V; cada estudiant de V
    nomes hi apareix un cop a v[0..pos], amb la nota mes alta i en el mateix
    ordre que a V 
*/
{
    pos = 1;
    int n = v.size();
    int i = 1;
    while (i < n)
    {
        if(v[pos-1].consultar_DNI() == v[i].consultar_DNI()) //1
        {
            if(v[i].te_nota()) //2
            {
                if(v[pos-1].te_nota()) //3
                {
                    if(v[pos-1].consultar_nota() < v[i].consultar_nota()) v[pos-1].modificar_nota(v[i].consultar_nota()); //4
                }
                else v[pos-1].afegir_nota(v[i].consultar_nota());
            }

        }
        else
        {
            ++pos;
            v[pos-1] = v[i];
        }
        ++i;
    }
    for(int j = 0; j < n-pos;++j)
    {
        v.pop_back();
    }
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
	int pos;
	simplificar_vector(v,pos);
    write(v);
	cout << pos;
}