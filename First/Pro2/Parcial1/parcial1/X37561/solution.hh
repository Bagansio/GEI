#include "Cjt_estudiants.hh"

void extreure_reavaluables(const Cjt_estudiants& c1, const Cjt_estudiants& c2,
                           double x, double y, double z, Cjt_estudiants& reava);
  /* Pre: c1 i c2 contenen els mateixos estudiants, reava es buit,
          0<=x,y,z<=Estudiant::nota_maxima(), x<=y */
  /* Post: el conjunt reava està format pels estudiants reavaluables de c1 i c2 
           respecte a x,y,z, tots sense nota */
