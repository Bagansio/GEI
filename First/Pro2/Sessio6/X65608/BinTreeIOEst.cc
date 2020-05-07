#include "BinTreeIOEst.hh"

void read_bintree_est(BinTree<Estudiant>& a)
{
    Estudiant x;
    x.llegir();
    if (x.consultar_DNI() != 0)
    {
        BinTree<Estudiant> a1;
        read_bintree_est(a1);
        BinTree<Estudiant> a2;
        read_bintree_est(a2);
        a = BinTree<Estudiant> (x,a1,a2);
    }
}

void write_bintree_est(const BinTree<Estudiant>& a)
{
    if (not a.empty())
    {
        write_bintree_est(a.left());
        a.value().escriure();
        write_bintree_est(a.right());
    }
}