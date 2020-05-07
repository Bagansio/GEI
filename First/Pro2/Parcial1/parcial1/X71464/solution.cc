// Poseu aqui vostre nom, cognoms i grup de laboratori



#include "Cjt_estudiants.hh"
#include "solution.hh"
#include <algorithm>

/* Traieu els comentaris "//" i completeu les operacions

   Recordeu que no podeu fer servir elements privats de les classes
   {\tt Cjt\_estudiants} i {\tt Es\-tu\-diant}
*/

bool nota_decr(const Estudiant& a, const Estudiant& b) {
  /* Pre: cert */
  /* Post: el resultat es cert si la nota d'a es mes gran que la de b
     o, si son iguals, si el dni d'a es mes petit que el de b */

   if (a.te_nota())
   {
      if (b.te_nota())
      {
         return (a.consultar_nota() > b.consultar_nota() or (a.consultar_nota() == b.consultar_nota() and a.consultar_DNI() < b.consultar_DNI()));
      }
      return true;
   }
   return a.consultar_DNI() < b.consultar_DNI();
}


void escriure_nota_decr(const Cjt_estudiants& c) {
  /* Pre: cert */
  /* Post: s'han escrit pel canal est�ndar de sortida els estudiants
     de c en ordre descendent de nota i, en cas d'empat, en ordre
     ascendent per DNI */
   
   int n = c.mida();
   vector<Estudiant> aux(n);
   for(int i = 1; i <= n; ++i) aux[i-1] = c.consultar_iessim(i);
   sort(aux.begin(),aux.end(),nota_decr);
   for(int i = 0; i < n; ++i) aux[i].escriure();
}
