#include "Cjt_estudiants.hh"
#include "PRO2Excepcio.hh"
#include <algorithm>
#include <iostream>

Cjt_estudiants::Cjt_estudiants()
{
  nest = 0;
  vest = vector<Estudiant>(MAX_NEST);
}

int Cjt_estudiants::cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x)
{
  int i;
  bool found=false;
  while (left <= right and not found) { 
    i = (left + right)/2;
    if (x < vest[i].consultar_DNI()) right = i - 1; 
    else if (x > vest[i].consultar_DNI()) left = i + 1; 
    else found = true;
  } 
  if (found) return i;
  else return left;
}  

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
  /* Pre: el paràmetre implícit no està ple */
  /* Post: b = indica si el p.i. original conté un estudiant amb el dni d'est;
     si b = fals, s'ha afegit l'estudiant est al paràmetre implícit */
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
    }
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b)
/* Pre: cert */
/* Post: b indica si el paràmetre implícit original tenia un estudiant 
   amb el dni dni; si b, aquest estudiant ha quedat eliminat
   del paràmetre implícit */
{
  int i = cerca_dicot(vest,0,nest-1,dni); 
  b = (i<nest) and (dni == vest[i].consultar_DNI());
  
  // b indica si hi ha un estudiant amb DNI = dni a vest; si b es cert, 
  // i es la posicio on es troba; 
  
  if (b) {
    // ara desplacem els elements següents a i per ocupar el lloc de vest[i],
    // actualitzem la mida i mirem si s'ha d'actualitzar imax
    for (int j = i; j < nest - 1; ++j) vest[j] = vest[j + 1];
    --nest; 
  }
}

Estudiant Cjt_estudiants::consultar_iessim(int i) const {
  if (i < 1 or i > nest) throw PRO2Excepcio("Index no valid per a consultar iessim");
  return vest[i-1];
}

int Cjt_estudiants::mida() const
{
  return nest;
}

int Cjt_estudiants::mida_maxima() 
{
  return MAX_NEST;
}
 
// implementacio intencionadament no optima
void Cjt_estudiants::llegir() {
  int k;
  cin >> k;  
  for (int i = 0; i < k; ++i) {
    Estudiant e;
    bool b;
    e.llegir();
    afegir_estudiant(e,b);
  }
}

void Cjt_estudiants::escriure() const {
  cout << nest << endl;
  for (int i = 0; i < nest; ++i)
    vest[i].escriure();
}


