#ifndef CONJ_EST_HH
#define CONJ_EST_HH

#include <vector>
#include <iostream>
#include "Estudiant.hh"

using namespace std;

class Cjt_estudiants {

private:

  // Representa un conjunt d'estudiants ordenat per DNI.  
  
  vector<Estudiant> vest; // estudiants del conjunt

  int nest; // nombre d'estudiants del conjunt 

  static const int MAX_NEST = 10; // nombre maxim d'elements del conjunt

  int nombre_aprovats; // nombre d'aprovats del conjunt
  
  int nombre_presentats;  // nombre de presentats del conjunt

  /* 
     Invariant de la representació: 
     - vest[0..nest-1] està ordenat creixentment pel dni dels estudiants i no conté estudiants repetits
     - 0 <= nest <= vest.size() = MAX_NEST
     - nombre_aprovats = nombre d'elements de vest[0..nest-1] amb nota >= Estudiant::nota_maxima();
     - nombre_presentats = nombre d'elements de vest[0..nest-1] amb nota 
  */
     
  static int cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x);
  /* Pre: els elements de vest estan ordenats creixentment per DNI,
     0 <= left, right < vest.size(), right >= left + 1 */
  /* Post: si x hi és vest[left..right], el resultat és la posició que
     hi ocupa, si no, és la posició que hauria d'ocupar */


public:

  //Constructores

  Cjt_estudiants();
  /* Pre: cert */
  /* Post: crea un conjunt d'estudiants buit */

  //Modificadores

  void afegir_estudiant(const Estudiant &est, bool& b);
  /* Pre: el paràmetre implícit no està ple */
  /* Post: b = indica si el p.i. original conté un estudiant amb el dni d'est;
     si b = fals, s'ha afegit l'estudiant est al paràmetre implícit */

  void esborrar_estudiant(int dni, bool& b);
  /* Pre: cert */
  /* Post: b indica si el paràmetre implícit original tenia un estudiant 
     amb el dni dni; si b, aquest estudiant ha quedat eliminat
     del paràmetre implícit */

  //Consultores
	
  int mida() const;
  /* Pre: cert */
  /* Post: El resultat és el nombre d'estudiants del paràmetre implícit */

  static int mida_maxima();
  /* Pre: cert */
  /* Post: el resultat és el nombre maxim d'estudiants que pot arribar
     a tenir el paràmetre implícit */

  int presentats() const;
  /* Pre: cert */
  /* Post: el resultat és el nombre d'estudiants del paràmetre implícit amb
     nota */
  
  int aprovats() const;
  /* Pre: cert */
  /* Post: el resultat és el nombre d'estudiants del paràmetre implícit amb
     nota >= Estudiant::nota_maxima()/2 */

  // Lectura i escriptura
	
  void llegir();
  /* Pre: estan preparats al canal estàndar d'entrada un enter  (entre 0 i la
     mida maxima permesa per a la classe), que representa el nombre d'elements 
     que llegirem, i les dades de tal nombre d'estudiants diferents */
  /* Post: el paràmetre implícit conté el conjunt d'estudiants llegits
     del canal estàndar d'entrada */

  void escriure() const;
  /* Pre: cert */
  /* Post: s'han escrit pel canal estàndar de sortida els estudiants del
     paràmetre implícit en ordre ascendent per DNI */
};

#endif

