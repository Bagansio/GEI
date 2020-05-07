#include <iostream>
#include <list>
using namespace std;


 void seleccio(const list<double>& l, list<double>& sel)
 /* Pre: l no es vacia, sol es vacia */
 /* Post: sel es el resultado de extraer de l los elementos debiles en media */
 {
     int nombre_anteriors = 1;
     double suma = *(l.begin());
     sel.push_back(suma);
     for (list<double>::const_iterator it = ++l.begin(); it != l.end(); ++it)
     {
         if(suma/nombre_anteriors <= *it) sel.push_back((*it));
         ++nombre_anteriors;
         suma += *it;
     }
 }