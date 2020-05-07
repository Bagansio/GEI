/* Poseu aqui vostre nom, cognoms i grup de laboratori:


*/

#include "Cjt_estudiants.hh"
#include "solution.hh"
#include <iostream>
using namespace std;
/* Traieu els comentaris "//" i completeu les operacions

   Recordeu que no podeu fer servir elements privats de les classes
   {\tt Cjt\_estudiants} i {\tt Es\-tu\-diant}
*/

void extreure_reavaluables(const Cjt_estudiants& c1, const Cjt_estudiants& c2,
                           double x, double y, double z, Cjt_estudiants& reava)
  /* Pre: c1 i c2 contenen els mateixos estudiants, reava es buit,
          0<=x,y,z<=Estudiant::nota_maxima(), x<=y */
  /* Post: el conjunt reava est� format pels estudiants reavaluables de c1 i c2 
           respecte a x,y,z, tots sense nota */
{
        int n = c1.mida();
        for (int i = 1; i <= n; ++i)
        {
                Estudiant auxc1 = c1.consultar_iessim(i);
                if (auxc1.te_nota())
                {
                        int notac1 = auxc1.consultar_nota();
                        if (notac1 >= x and notac1 <= y)
                        {
                                if (c2.consultar_iessim(i).te_nota() and c2.consultar_iessim(i).consultar_nota() >= z)
                                {
                                        Estudiant est(auxc1.consultar_DNI());
                                        bool b;
                                        reava.afegir_estudiant(est,b);
                                }
                        }
                }
        }
}
