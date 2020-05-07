#include "Cjt_estudiants.hh"
using namespace std;

void final(Cjt_estudiants& primer, const Cjt_estudiants& segon)
{
    int n = primer.mida();
    for (int i = 1; i <= n; ++i)
    {
        Estudiant aux = primer.consultar_iessim(i);
        int dni = aux.consultar_DNI();
        if(segon.existeix_estudiant(dni))
        {
            Estudiant aux2 = segon.consultar_estudiant(dni);
            if(aux.te_nota())
            {
                if (aux2.te_nota())
                {
                if(aux.consultar_nota() < aux2.consultar_nota()) primer.modificar_estudiant(aux2);
                }
        }
        else primer.modificar_estudiant(aux2);
        }
    }
} 

int main(){
    Cjt_estudiants primer;
    Cjt_estudiants segon;
    primer.llegir(); // = omplir_conjunt();
    segon.llegir(); //= omplir_conjunt();
    if(primer.mida() >= segon.mida())
    {
        final(primer,segon);
        primer.escriure();
    }
    else
    {
        final(segon,primer);
        segon.escriure();
    }
}