// Poseu aqui vostre nom, cognoms i grup de laboratori

#include "Cjt_estudiants.hh"

// Traieu els //, /*, etc. adients i completeu les operacions

/* Operaci� afegir_estudiant: el codi que us donem compila sense error i fa
   coses correctes, per� clarament insuficients; analitzeu amb cura quins
   camps de la classe resten per actualitzar
*/

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
  /* Pre: el par�metre impl�cit no est� ple */
  /* Post: b = indica si el p.i. original cont� un estudiant amb el dni d'est;
     si b = fals, s'ha afegit l'estudiant est al par�metre impl�cit */
{
  int x = est.consultar_DNI();
  int i = cerca_dicot(vest,0,nest-1,x);
  b = (i<nest) and (x== vest[i].consultar_DNI());
    
  // b indica si est hi es a vest; si b es fals, i es la posicio on ha
  // d'anar est per mantenir l'ordre a vest; 
 
  if (not b) {
    for (int j=nest; j>i; --j) vest[j] = vest[j-1];
    vest[i] = est;
    ++nest;
      if(est.te_nota())
      {
         if (est.consultar_nota() >= min_nota_beca)
         {
            if (max_beques > num_beques)
            {
               ++num_beques;
            }
         }
      }
      else if (num_beques != 0)
      {
         cout << "-------------" << endl;
         becat_menys_prioritari().escriure();
         pitjor_becat = cerca_dicot(vest,0,nest-1,becat_menys_prioritari().consultar_DNI());

      }
      cout << pitjor_becat << "llll"  << num_beques << endl;
  }
}


/* Operaci� immediatament_millor: la linia del cout no pinta res i haurieu de
   treure-la quan comenceu a implementar l'operaci�, per� permet fer
   lliuraments sense error de compilaci�, de forma que l'altra operaci� es
   podria avaluar manualment
*/

int Cjt_estudiants::immediatament_millor(int i) const
/* Pre: 0<=i<nest; vest[i] te nota */
/* Post: el resultat �s la posici� en vest[0..nest-1] de l'estudiant
   immediatament millor que vest[i], si n'hi ha; -1 en cas contrari */
{
  int j = -1;
   int nota_aux = -1;
   while (i >= 0)
   {
      if (vest[i].te_nota())
      {
         if (vest[i].consultar_nota() > nota_aux)
         {
            nota_aux = vest[i].consultar_nota();
            j = i;
         }
      }
      --i;
   }
//cout << vest[i].consultar_nota() << endl;
//  normalment s'hauria de deixar com a comentari

  return j;
}


