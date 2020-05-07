#include <algorithm>
#include <iostream>
#include "Cjt_estudiants.hh"

using namespace std;

Cjt_estudiants::Cjt_estudiants()
{
  nest = 0;
  vest = vector<Estudiant>(MAX_NEST);
  nombre_suspesos=0;
  nombre_compensables=0;
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

int Cjt_estudiants::mida() const
{
  return nest;
}

int Cjt_estudiants::mida_maxima() 
{
  return MAX_NEST;
}
 
int Cjt_estudiants::suspesos() const {
  return nombre_suspesos;
}

int Cjt_estudiants::compensables() const {
  return nombre_compensables;
}

// implementacio intencionadament no optima
void Cjt_estudiants::llegir() {
  nest = 0;
  nombre_suspesos=0;
  nombre_compensables=0;
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

