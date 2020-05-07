#include "BinTreeIOEst.hh"

int encontrar(const BinTree<Estudiant>& arbol, int n, int& nota)
{
    if(not arbol.empty())
    {
        Estudiant est = arbol.value();
        if (est.consultar_DNI() == n)
        {
            if (est.te_nota()) nota = est.consultar_nota();
            else nota = -1;
            return 0;
        }
        int left = encontrar(arbol.left(),n,nota);
        int nota_aux;
        int right = encontrar(arbol.right(),n,nota_aux);
        if (left != -1 and right != -1)
        {
            if (left <= right) return left + 1;
            else 
            {
                nota = nota_aux;
                return right + 1;
            }
        }
        if (left != -1) return left + 1;
        else if (right != -1)
        {
            nota = nota_aux;
            return right + 1;
        }
        else return -1;
    }
    return -1;
}

int main()
{
    BinTree<Estudiant> arbol;
    read_bintree_est(arbol);
    int n;
    while (cin >> n)
    {
        int nota;
        int altura = encontrar(arbol,n,nota);
        cout << n << ' ';
        if (altura != -1) cout << altura << ' ' << nota;
        else cout << -1;
        cout << endl;
    }
}