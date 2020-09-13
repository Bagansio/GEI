/** @file   Cluster.hh
    @brief  Especificación de la clase Cluster
*/
#ifndef CLUSTER_HH
#define CLUSTER_HH

#include "cjt_especies.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#endif 

struct especie{
    string id,gen;
};

/** @class Cluster
 *  @brief Representa un cluster formado por especies con identificador y gen.
 */
class Cluster  
{

private:

BinTree<especie> cluster;

public:


};