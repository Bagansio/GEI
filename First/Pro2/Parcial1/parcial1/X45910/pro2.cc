#include <iostream>
#include "Cjt_estudiants.hh"

using namespace std;

int main() {
  Cjt_estudiants c;
  Cjt_estudiants d;
  c.llegir(); 
  int op;
  cin >> op;
  while (op != -7){
    Estudiant est; bool b;
    switch (op) { 
    case -1:   // afegir
      est.llegir();
      c.afegir_estudiant(est, b);
      if (b)  cout << "l'estudiant " << est.consultar_DNI() << " ja hi era" << endl << endl;
      break;
    case -2:   // unir
      d.llegir(); 
      c.unir_conjunts(d);
      break; 
    case -3:   // actualitzar 
      c.actualitzar_conjunt(); 
      break;
    case -4:   // modificar nota per dni
      est.llegir();
      c.modificar_estudiant(est, b);
      if (not b) cout << "l'estudiant " << est.consultar_DNI() << " no hi es" << endl << endl;
      break;
    case -5:   // escriure el conjunt
      cout << "Conjunt:" << endl;
      c.escriure();
      cout << endl;
      break;
    case -6:   // escriure l'estudiant de nota maxima
      cout << "Nota max: ";
      c.estudiant_nota_max().escriure();
      c.unir_conjunts(c); 
      cout << endl;
      break;
    }
    cin >> op; 
  }
}

