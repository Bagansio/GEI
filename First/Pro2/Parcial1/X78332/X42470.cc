#include "BinTree.hh"
#include <iostream>
#include "BinTreeIOint.hh"

pair<int,BinTree<int>> i_arbre_graus_desequilibri(const BinTree<int> &a)
{
    if (a.empty())
    {
        pair<int,BinTree<int>> aux;
        BinTree<int> b;
        aux.first = 0;
        aux.second = b;
        return aux;
    }
    else
    {
        pair<int,BinTree<int>> left = i_arbre_graus_desequilibri(a.left());
        pair<int,BinTree<int>> right = i_arbre_graus_desequilibri(a.right());
        
        left.second = BinTree<int> (left.first - right.first,left.second,right.second);
        if (left.first < right.first) left.first = right.first + 1;
        else ++left.first;
        return left;
    }
}

 void arbre_graus_desequilibri(const BinTree<int> &a, BinTree<int> &agd)
 /* Pre: a=A */
 /* Post: agd es un arbre amb la mateixa estructura que A on cada
    node conte el grau de desequilibri del subarbre d'A corresponent */
{
    pair<int,BinTree<int>> aux = i_arbre_graus_desequilibri(a);
    agd = aux.second;
}
/*
int main()
{
    BinTree<int> a,agd;
    read_bintree_int(a,0);
    arbre_graus_desequilibri(a,agd);
    write_bintree_int(a);
    write_bintree_int(agd);
}*/