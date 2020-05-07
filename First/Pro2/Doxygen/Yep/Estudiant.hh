/** @file Estudiant.hh
 *  @brief Especificación de la clase Estudiant
*/
#ifndef ESTUDIANT_HH
#define ESTUDIANT_HH

#ifndef NO_DIAGRAM   
#include "PRO2Excepcio.hh"
#include <iostream>
#endif     

/** @class Estudiant
 * @brief Representa un estudiante con DNI.
 * 
 * Puede tener nota y en tal caso su máxima nota es un 10
 */

class Estudiant {
    
  // Tipus de modul: dades
  // Descripcio del tipus: conte el DNI d'un estudiant,
  // que es un enter positiu, i pot tenir nota, que seria un double
  // Les notes valides son les de l'interval 0..nota_maxima()
    
private:
  int dni;
  double nota;
  bool amb_nota;
  static const int MAX_NOTA = 10;
  /*
    Invariant de la representacio:
    - 0 <= dni
    - si amb_nota, llavors 0 <= nota <= MAX_NOTA
  */
    
public:
  //Constructores
  
  /** @brief Creadora por defecto.
   * 
   * Se ejecuta automáticamente al declarar un estudiante.
   * \pre <strong><em>Cierto</em></strong>
   * \post El resultado es un estudiante con DNI = 0 y sin nota
   * \coste Constante
   */
  Estudiant();
  /* Pre: cert */
  /* Post: el resultat es un estudiant amb DNI = 0 i sense nota */

  /** @brief Creadora de un estudiante con DNI.
   * 
   * \pre <strong>dni >= 0</strong>
   * \post El resultado es un estudiante con DNI = dni y sin nota
  */
  Estudiant(int dni);
  /* Pre: dni >= 0 */
  /* Post: el resultat es un estudiant amb DNI = dni i sense nota */
    
  // Destructora: esborra automaticament els objectes locals en sortir
  // d'un ambit de visibilitat

  
  /** @brief Destructora por defecto.
   */    
  ~Estudiant();
    
  //Modificadores
  
  /** @brief Añade una nota al estudiante.
   * 
   * \pre El parámetro implícito no tiene nota, 0 <= "nota" <= nota_maxima() 
   * \post La nota del parámetro implícito pasa a ser "nota"
   */ 
  void afegir_nota(double nota);
  /* Pre: el parametre implicit no te nota, 0 <= "nota" <= nota_maxima() */
  /* Post: la nota del parametre implicit passa a ser "nota" */

  /** @brief Modifica la nota del estudiante.
   * 
   * \pre El parámetro implícito tiene nota,  0 <= "nota" <= nota_maxima() 
   * \post La nota del parámetro implícito pasa a ser "nota"
   */  
  void modificar_nota(double nota);
  /* Pre: el parametre implicit te nota, 0 <= "nota" <= nota_maxima() */
  /* Post: la nota del parametre implicit passa a ser "nota" */
    
  //Consultores

  /** @brief Consultora del DNI del estudiante.
   * 
   * \pre <em>Cierto</em>
   * \post El resultado es el DNI del parámetro implícito
   */   
  int consultar_DNI() const;
  /* Pre: cert  */
  /* Post: el resultat es el DNI del parametre implicit */

  /** @brief Consultora de la nota del estudiante.
   * 
   * \pre El parámetro implícito tiene nota
   * \post El resultado es la nota del parámetro implícito
   */   
  double consultar_nota() const;
  /* Pre: el parametre implicit te nota */
  /* Post: el resultat es la nota del parametre implicit */

  /** @brief Consultora de la nota máxima posible de un estudiante.
   * 
   * \pre <em>Cierto</em>
   * \post El resultado es la nota máxima de los elementos de la clase.
   */   
  static double nota_maxima();
  /* Pre: cert */
  /* Post: el resultat es la nota maxima dels elements de la classe */

  /** @brief Consultora de si el estudiante tiene nota.
   * 
   * \pre <em>Cierto</em>
   * \post El resultado indica si el parámetro implícito tiene nota o no
   */   
  bool te_nota()  const;
  /* Pre: cert  */
  /* Post: el resultat indica si el parametre implicit te nota o no */
  
  // Lectura i escriptura
  /** @brief Comparación de estudiantes.
   * 
   * \pre <em>Cierto</em>
   * \post El resultado indica si el DNI de e1 es más pequeño que el de e2
   */
  static bool comp(const Estudiant& e1, const Estudiant& e2); 
  /* Pre: cert  */
  /* Post: el resultat indica si el DNI d'e1 es m�s petit que el d'e2 */

  /** @brief Operación de lectura.
   * 
   * \pre Hay preparado en el canal estandard de entrada un entero no negativo y un double
   * \post El parámetro implícito pasa a tener los atributos leídos del canal estandard de entrada,<br> en el caso que el double no pertenezca al intervalo [0,nota_maxima()] no tendrá nota 
   */   
  // Lectura i escriptura
  void llegir();
  /* Pre:  hi ha preparats al canal estandard d'entrada un enter no negatiu 
     i un double */
  /* Post: el parametre implicit passa a tenir els atributs llegits
     del canal estandard d'entrada; si el double no pertany a l'interval
     [0..nota_maxima()], el p.i. es queda sense nota */

  /** @brief Operación de escritura.
   * 
   * \pre <em>Cierto</em>
   * \post Se han escrito los atributos del parámetro implícito al canal estandard de salida;<br> sino tiene nota escribe "NP"
   */   
  void escriure() const;
  /* Pre: cert */
  /* Post: s'han escrit els atributs del parametre implicit
     al canal estandard de sortida; si no te nota escriu "NP" */
};
#endif
