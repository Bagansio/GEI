#include "Estudiant.hh"
#include <vector>
using namespace std;

void simplificar_vector(vector<Estudiant>& v, int& pos)
/* Pre: v=V, v.size() > 0 i les notes d'un mateix estudiant son consecutives */
/* Post: pos+1 es el nombre d estudiants diferents de V; cada estudiant de V
    nomes hi apareix un cop a v[0..pos], amb la nota mes alta i en el mateix
    ordre que a V 
*/
{
    pos = 0;
    int n = v.size();
    for (int i = 1; i < n; ++i)
    {
        if(v[pos].consultar_DNI() == v[i].consultar_DNI()) //1
        {
            if(v[i].te_nota()) //2
            {
                if(v[pos].te_nota() and v[pos].consultar_nota() < v[i].consultar_nota()) //3
                {
                    v[pos].modificar_nota(v[i].consultar_nota()); //4
                }
                else if(not v[pos].te_nota())
                {
                    v[pos].afegir_nota(v[i].consultar_nota());
                }
            }

        }
        else
        {
            ++pos;
            swap(v[pos],v[i]);
        }
    }
}