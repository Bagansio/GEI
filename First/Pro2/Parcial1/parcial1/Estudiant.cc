#include <iostream>
#include "PRO2Excepcio.hh"
#include "Estudiant.hh"

using namespace std;

/* Constantes */

const char *ER1 = "No te nota";
const char *ER2 = "Valor de la nota entre 0 a 10";
const char *ER3 = "Ja te nota";
const char *ER4 = "El DNI es incorrecte";

Estudiant::Estudiant(){
  dni=0;
  amb_nota = false;
}

Estudiant::Estudiant(int n)
{
  if (n<0) throw PRO2Excepcio(ER4);
  dni = n;
  amb_nota = false;
}

Estudiant::~Estudiant(){}

void Estudiant::afegir_nota(double x)
{
  if (amb_nota) 
    throw PRO2Excepcio(ER3);
  if (x<0 or x>MAX_NOTA)
    throw PRO2Excepcio(ER2); 
  
  nota = x; 
  amb_nota = true;
}

void Estudiant::modificar_nota(double x)
{ 				
  if (not amb_nota) 
    throw PRO2Excepcio(ER1);
  if (x<0 or x>MAX_NOTA)
    throw PRO2Excepcio(ER2);
  nota = x;
}

bool Estudiant::te_nota() const
{
  return amb_nota;
}

double Estudiant::consultar_nota() const
{
  if (not amb_nota) throw PRO2Excepcio(ER1);
  return nota;
}

int Estudiant::consultar_DNI() const
{
  return dni;
}

double Estudiant::nota_maxima()
{
  return MAX_NOTA;
}

void Estudiant::llegir()
{
  cin >> dni; 
  if (dni<0) throw PRO2Excepcio(ER4);
  double x;
  cin >> x;
  if (x >= 0 and x <= MAX_NOTA) {
    nota = x; 
    amb_nota = true;
  }
  else amb_nota = false;
}

void Estudiant::escriure() const
{
  if (amb_nota)
    cout << dni << " " << nota << endl;
  else
    cout << dni <<" NP" << endl;
}

bool Estudiant::mes_prioritari(const Estudiant& e) const 
{
  if (not amb_nota and not e.amb_nota) return dni > e.dni;
  else if (not amb_nota) return false;
  else if (not e.amb_nota) return true;
  else return nota>e.nota or (nota==e.nota and dni > e.dni);
} 

