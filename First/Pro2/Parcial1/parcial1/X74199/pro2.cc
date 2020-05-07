#include <iostream>
#include "Cjt_estudiants.hh"

using namespace std;

int main() {
  Cjt_estudiants c;
  c.llegir();
  int op; 
  cin >> op;
  while (op != -5) {
    Estudiant est; 
    bool b; 
    switch (op) { 
    case -1:   // afegir estudiant
      est.llegir();
      c.afegir_estudiant(est, b);
      if (b)  cout << "L'estudiant " << est.consultar_DNI() << " ja hi era" << endl << endl;
      else {cout << "Afegit "; est.escriure(); cout << endl;}
      break;

    case -2:   // escriure conjunt
      cout << "Conjunt:" << endl;
      c.escriure();
      cout << endl;
      break;
    case -3: {  // nombre de becats i ptijor becat
      cout << "Estudiants amb beca del conjunt: ";
      
      int n = c.estudiants_amb_beca();
      cout << n << endl;
      if (n>0){
	cout << "El becat menys prioritari del conjunt es ";
	c.becat_menys_prioritari().escriure();
	
      }
      cout << endl;
      break;
    }
    case -4: {// torna a llegir conjunt
      c.llegir();
      cout << "Hem llegit un nou conjunt " << endl << endl;
      break;
    }
    }
    cin >> op;
  }
}
