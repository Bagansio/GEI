// Poseu aqui vostre nom, cognoms i grup de laboratori



#include "Cjt_estudiants.hh"

// Traieu els comentaris (excepte els de les especificacions) i
// completeu les operacions

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
 
  if (not b)
    {
      for (int j=nest; j>i; --j) vest[j] = vest[j-1];
      vest[i] = est;
      ++nest;
      if (est.te_nota())
      {
        ++nombre_presentats;
        if (est.consultar_nota() >= est.nota_maxima()/2) ++nombre_aprovats;
      }
    }
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b)
  /* Pre: cert */
  /* Post: b indica si el par�metre impl�cit original tenia un estudiant 
     amb el dni dni; si b, aquest estudiant ha quedat eliminat
     del par�metre impl�cit */
{
  int i = cerca_dicot(vest,0,nest-1,dni); 
  b = (i<nest) and (dni == vest[i].consultar_DNI());
 
  // b indica si hi ha un estudiant amb DNI = dni a vest; si b es cert, 
  // i es la posicio on es troba; 

  if (b) {
    // ara desplacem els elements seg�ents a i per ocupar el lloc de vest[i]
    // i actualitzem la mida

    if (vest[i].te_nota())
    {
      --nombre_presentats;
      if(vest[i].consultar_nota() >= vest[i].nota_maxima()/2) --nombre_aprovats;
    }
    for (int j = i; j < nest - 1; ++j) vest[j] = vest[j + 1];
    --nest; 
  }
}

