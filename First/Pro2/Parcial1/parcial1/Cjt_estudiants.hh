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

  int max_beques, num_beques;
  
  double min_nota_beca;

  int pitjor_becat; // posicio de l'estudiant becat menys prioritari
		    // (o -1 si no n'hi ha cap)

  /* 
     Invariant de la representació: 
     - vest[0..nest-1] està ordenat creixentment pel dni dels estudiants i no conté estudiants repetits
     - 0 <= nest <= vest.size() = MAX_NEST
     - 0 <= min_nota_beca <= Estudiant::nota_maxima()
     - 0 <= num_beques <= max_beques <= nest
     - num_beques = min(max_beques, nombre d'elements de vest[0..nest-1] amb nota >=min_nota_beca)  
     - 0 <= pitjor_becat < nest si i nomes si hi ha cap estudiant a vest[0..nest-1]
       amb nota >= min_nota_beca; en cas afirmatiu, v[pitjor_becat] es l'estudiant
       becat menys prioritari; en cas contrari, pitjor_becat=-1
  */
     
  static int cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x);
  /* Pre: els elements de vest estan ordenats creixentment per DNI,
     0 <= left, right < vest.size(), right >= left + 1 */
  /* Post: si x hi és vest[left..right], el resultat és la posició que
     hi ocupa, si no, és la posició que hauria d'ocupar */

  // Operacio nova: 
   int immediatament_millor(int i) const;
  /* Pre: 0<=i<nest; vest[i] te nota */
  /* Post: el resultat és la posició en vest[0..nest-1] de l'estudiant
     immediatament millor que vest[i], si n'hi ha; -1 en cas contrari */ 

  
public:

  //Constructores

  Cjt_estudiants();
  /* Pre: cert */
  /* Post: crea un conjunt d'estudiants buit amb un maxim de 0 beques
     i nota minima per tenir beca = Estudiant::nota_maxima() */

  //Modificadores

  void afegir_estudiant(const Estudiant &est, bool& b);
  /* Pre: el paràmetre implícit no està ple */
  /* Post: b = indica si el p.i. original conté un estudiant amb el dni d'est;
     si b = fals, s'ha afegit l'estudiant est al paràmetre implícit */


  //Consultores

  
  Estudiant consultar_iessim(int i) const;
  /* Pre: 1 <= i <= nombre d'estudiants que conte el parametre implicit */
  /* Post: el resultat es l'estudiant i-essim del parametre implicit
     en ordre creixent per DNI */

  int mida() const;
  /* Pre: cert */
  /* Post: El resultat és el nombre d'estudiants del paràmetre implícit */

  static int mida_maxima();
  /* Pre: cert */
  /* Post: el resultat és el nombre maxim d'estudiants que pot arribar
     a tenir el paràmetre implícit */

  // Operacio nova:
  int estudiants_amb_beca() const;
  /* Pre: cert */
  /* Post: el resultat és el nombre d'estudiants amb beca del p.i. */

  // Operacio nova: retorna l'estudiant amb mes possibilitat de perdre la beca
  Estudiant becat_menys_prioritari() const;
  /* Pre: el p.i. conté com a minim un estudiant amb beca */
  /* Post: el resultat és el becat amb menys prioritat del p.i. */

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

