// Poseu aqui vostre nom, cognoms i grup de laboratori

#include "Cjt_estudiants.hh"
#include "solution.hh"
#include <algorithm>

/* Traieu els comentaris "//" i completeu les operacions

   Recordeu que no podeu fer servir elements privats de les classes
   {\tt Cjt\_estudiants} i {\tt Es\-tu\-diant}
*/

void escriure_becats(const Cjt_estudiants& c) {
  /* Pre: cert */
  /* Post: s'han escrit pel canal est�ndar de sortida els estudiants
     de c amb beca en ordre ascendent per DNI */

   int num_beques = c.estudiants_amb_beca();
   cout << num_beques << endl;
   int i = 0;
   int maxi = c.mida();
   while (num_beques > 0 and i < maxi)
   {
      Estudiant min = c.becat_menys_prioritari();
      Estudiant iesim = c.consultar_iessim(i); 
      if (iesim.te_nota())
      {
         if (iesim.mes_prioritari(min) or min.consultar_DNI() == iesim.consultar_DNI())
         {
            iesim.escriure();
            --num_beques;
         }
      }
      ++i;
   }
}