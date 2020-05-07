// Poseu aqui vostre nom, cognoms i grup de laboratori



#include "Cjt_estudiants.hh"

// Traieu els comentaris // abans de posar codi a les funcions

void Cjt_estudiants::unir_conjunts(const Cjt_estudiants & c){
/* Pre: tots els dni de c hi són al p.i. */
/* Post: cada Estudiant del paràmetre implicit conté la millor nota entre 
   l'original i la que pugui tenir a c */ 
   int n = c.mida();
   int i,j;
   i = j = 0;
   while (i < n and j < nest)
   {
      if (vest[j].consultar_DNI() == c.vest[i].consultar_DNI())
      {
         if(c.vest[i].te_nota())
         {
            if (vest[j].te_nota())
            {
               if(vest[j].consultar_nota() < c.vest[i].consultar_nota()) vest[j].modificar_nota(c.vest[i].consultar_nota());
            }
            else vest[j].afegir_nota(c.vest[i].consultar_nota());
         }
         ++i;
      }
      ++j;
   }
   recalcular_posicio_imax();
} 


void Cjt_estudiants::actualitzar_conjunt() {
/* Pre: a l'entrada estàndar hi ha una seqüència d'Estudiant (seguida d'un
   Estudiant amb dni 0 que no forma part de la seqüència), amb els dni
   ordenats creixentment i tots hi són al p.i. */
/* Post: cada Estudiant del paràmetre implicit conté la millor nota entre l'original
   i la que pugui tenir a la seqüència */ 

   vector<Estudiant> seq;
   Estudiant aux;
   int n = 0;
   aux.llegir();
   while(aux.consultar_DNI() != 0) 
   {
      seq.push_back(aux);
      ++n;
      aux.llegir();
   }
   int i,j;
   i = j = 0;
   while (i < n and j < nest)
   {
      if (vest[j].consultar_DNI() == seq[i].consultar_DNI())
      {
         if(seq[i].te_nota())
         {
            if (vest[j].te_nota())
            {
               if(vest[j].consultar_nota() < seq[i].consultar_nota()) vest[j].modificar_nota(seq[i].consultar_nota());
            }
            else vest[j].afegir_nota(seq[i].consultar_nota());
         }
         ++i;
      }
      ++j;
   }
   recalcular_posicio_imax();
   
}
