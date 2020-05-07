#include "Cjt_estudiants.hh"

bool nota_decr(const Estudiant& a, const Estudiant& b);
  /* Pre: cert */
  /* Post: el resultat es cert si la nota d'a es mes gran que la de b
     o, si son iguals, si el dni d'a es mes petit que el de b */

void escriure_nota_decr(const Cjt_estudiants& c);
  /* Pre: cert */
  /* Post: s'han escrit pel canal estàndar de sortida els estudiants
     de c en ordre descendent de nota i, en cas d'empat, en ordre
     ascendent per DNI */
