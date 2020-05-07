#include <algorithm>
#include <iostream>
#include "Cjt_estudiants.hh"
#include "PRO2Excepcio.hh"

using namespace std;

Cjt_estudiants::Cjt_estudiants()
{
  nest = 0;
  vest = vector<Estudiant>(MAX_NEST);
  max_beques = 0;
  num_beques = 0;
  min_nota_beca = Estudiant::nota_maxima();
  pitjor_becat = -1;
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


int Cjt_estudiants::estudiants_amb_beca() const{
  return num_beques;
}

Estudiant Cjt_estudiants::becat_menys_prioritari() const {
  return vest[pitjor_becat];
}


// implementacio intencionadament no optima
void Cjt_estudiants::llegir() {
  cin>>max_beques >> min_nota_beca;
  nest = 0;
  num_beques = 0;
  pitjor_becat = -1;
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


