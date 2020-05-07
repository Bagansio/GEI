/** @file Cjt_estudiants.hh
 *  @brief Especificación de la clase Conjunto de Estudiantes
*/

#ifndef CONJ_EST_HH
#define CONJ_EST_HH

#include "Estudiant.hh"
#ifndef NO_DIAGRAM   
#include <vector>
#endif     

/** @class Cjt_estudiants
 *  @brief Representa un conjunto de estudiantes ordenados por DNI
 */   
class Cjt_estudiants {

private:

  // Representa un conjunt d'estudiants ordenat per DNI.  
  
  vector<Estudiant> vest;
  int nest; 
  static const int MAX_NEST = 20; // nombre maxim d'elements del conjunt
  int nest_amb_nota;  
  double suma_notes;

  /* 
     Invariant de la representaci�: 
     - vest[0..nest-1] est� ordenat creixentment pel DNI dels estudiants
       i no cont� estudiants repetits
     - 0 <= nest_amb_nota <= nest <= vest.size() = MAX_NEST
     - nest_amb_nota �s el nombres d'estudiants amb nota de vest[0..nest-1]
     - suma_notes �s la suma de les notes (dels estudiants amb nota) de vest[0..nest-1]
  */  
    
  void ordenar_cjt_estudiants();
  /* Pre: cert */
  /* Post: el elements del par�metre impl�cit passen a estar ordenats
     creixentment per DNI. */
     
  static int cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x);
  /* Pre: els elements de vest estan ordenats creixentment per DNI,
     0<=left, right<vest.size(), right>=left-1 */
  /* Post: si x hi �s vest[left..right], el resultat �s la posici� que
     hi ocupa, si no, �s la posici� que hauria d'ocupar */
 
public:

  //Constructores


/** @brief Creadora por defecto.
 * 
 * Se ejecuta automáticamente al declarar un conjunto de estudiantes.
 *  \pre <em>Cierto</em>
 *  \post  Crea un conjunto de estudiantes vacio
 */
  Cjt_estudiants();
  /* Pre: cert */
  /* Post: crea un conjunt d'estudiants buit */

  //Modificadores

/** @brief  Añade un estudiante al conjunto.
 * 
 *  \pre El parámetro implícito no esta lleno
 *  \post b = indica si el parámetro implícito original contiene un estudiante con el dni de este, <br>si b = falso, se ha añadido el estudiante al parámetro implícito
 */
  void afegir_estudiant(const Estudiant &est, bool& b);
  /* Pre: el par�metre impl�cit no est� ple */
  /* Post: b = indica si el p.i. original cont� un estudiant amb el dni d'est;
     si b = fals, s'ha afegit l'estudiant est al par�metre impl�cit */

/** @brief  Borrar un estudiante del conjunto.
 * 
 *  \pre <em>Cierto</em>
 *  \post b = true, el parámetro implícito original tenia un estudiante con ese DNI y lo ha borrado, b = false, no estaba  y por tanto no lo ha borrado
 */
  void esborrar_estudiant(int dni, bool& b);
  /* Pre: cert */
  /* Post: b indica si el par�metre impl�cit original tenia un estudiant 
     amb el dni dni; si b, aquest estudiant ha quedat eliminat
     del par�metre impl�cit */

  //Consultores

/** @brief  Mida del conjunto de estudiantes
 * 
 *  \pre <em>Cierto</em>
 *  \post El resultado es el numero de estudiantes del parámetro implícito
 */	
  int mida() const;
  /* Pre: cert */
  /* Post: El resultat �s el nombre d'estudiants del par�metre impl�cit */

/** @brief Mida máxima del conjunto de estudiantes
 * 
 *  \pre <em>Cierto</em>
 *  \post El resultado es el numero máximo de estudiantes que puede llegar a tener el parámetro implícito
 */
  static int mida_maxima();
  /* Pre: cert */
  /* Post: el resultat es el nombre maxim d'estudiants que pot arribar
     a tenir el parametre implicit */

 /** @brief Media de los estudiantes con nota
 * 
 *  \pre <em>Cierto</em>
 *  \post El resultado es la media de las notas de los estudiantes con nota del parámetro implícito, si no hay ninguna el resultado es -1
 */ 
  double mitjana_estudiants_amb_nota() const;
  /* Pre: cert */
  /* Post: el resultat �s la mitjana de les notes dels estudiants amb nota
     del par�metre impl�cit; si no n'hi ha cap, el resultat �s -1 */ 

  // Lectura i escriptura

/** @brief Operación de lectura.
 * 
 *  \pre <em>Cierto</em>
 *  \post El parámetro implícito contiene el conjunto de estudiantes leídos del canal estandard de entrada
 */	
  void llegir();
  /* Pre: cert */
  /* Post: el par�metre impl�cit cont� el conjunt d'estudiants llegits
     del canal est�ndar d'entrada */

/** @brief  Operación de escritura.
 * 
 *  \pre <em>Cierto</em>
 *  \post Se han escrito por el canal estandard de salida a los estudiantes del conjunto que contiene <br> el parámetro implícito ordenados en orden ascendente del DNI
 */
  void escriure() const;
  /* Pre: cert */
  /* Post: s'han escrit pel canal est�ndar de sortida 
     els estudiants del conjunt que cont� el par�metre 
     impl�cit en ordre ascendent per DNI */

};

#endif
