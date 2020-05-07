#include "BinTreeIOParInt.hh"
#include <iostream>
using namespace std;

void encontrado(const BinTree <ParInt>& arbol, int n, int p, bool& found)
{

    if (not arbol.empty())
    {
        if(arbol.value().primer() == n)
        {
            cout << n << ' ' << arbol.value().segon() << ' ' << p;
            found = true;
        }
        else{
            encontrado(arbol.left(),n, p+1,found);
            encontrado(arbol.right(),n,p+1,found);
        }
    }
}

int main (){
    BinTree <ParInt> arbol;
    read_bintree_parint(arbol);
    int n;
    while (cin >> n)
    {
        bool found = false;
        encontrado(arbol,n,0,found);
        if (not found) cout << -1;
        cout << endl;
    }
}