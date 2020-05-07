#include "BinTreeIOParInt.hh"

void read_bintree_parint(BinTree<ParInt>& a)
{
    ParInt x;
    x.llegir();
    if (x.primer() != 0)
    {
        BinTree <ParInt> a1;
        read_bintree_parint(a1);
        BinTree <ParInt> a2;
        read_bintree_parint(a2);
        BinTree <ParInt> aux (x,a1,a2);
        a = aux;
    }
    else
    {
        BinTree<ParInt> aux;
        a = aux;
    }
}

void write_bintree_parint(const BinTree<ParInt>& a)
{
    if (not a.empty())
    {
        write_bintree_parint(a.left());
        a.value().escriure();
        write_bintree_parint(a.right());
    }
}
