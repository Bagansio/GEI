#include "BinTree.hh"
//#include "BinTreeIOint.hh"
//using namespace std;

bool poda_subarbre(BinTree<int> &a, int x)
{
    bool podat = false;
    if (not a.empty())
    {
        if(a.value() == x)
        {
            BinTree<int> aux;
            a = aux;
            podat = true;
        }
        else{
            BinTree<int> a1 = a.left();
            podat = poda_subarbre(a1,x);
            BinTree<int> a2 = a.right();
            if (not podat) {
                podat = poda_subarbre(a2,x);
            }
            a = BinTree<int> (a.value(),a1,a2);
        }
    }
    return podat;
}
/*
int main(){
    BinTree<int> a;
    read_bintree_int(a,0);
    write_bintree_int(a);
    int n;
    cin >> n;
    if (poda_subarbre(a,n)) write_bintree_int(a);
    else cout << "no";
}*/