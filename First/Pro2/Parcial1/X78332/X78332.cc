#include "BinTree.hh"
#include <stack>
#include <vector>
#include "BinTreeIOint.hh"


pair<int,vector<int>> i_cami_preferent(const BinTree<int>& a)
{
    if (a.empty())
    {
        vector <int> vect(0);
        pair<int,vector<int>> aux;
        aux.first = 0;
        aux.second = vect;
        return aux;
    }
    else{
        pair<int,vector<int>> left = i_cami_preferent(a.left());
        pair<int,vector<int>> right = i_cami_preferent(a.right());
        
        if(left.first >= right.first)
        {
            left.second.push_back(a.value());
            left.first = left.first + right.first + 1;
            return left;
        }
        right.second.push_back(a.value());
        right.first = right.first + left.first + 1;
        return right;
    }
}


 void cami_preferent(const BinTree<int>& a, stack<int>& c)
 /* Pre: c esta vacia */
 /* Post: c contiene el camino preferente de a; si no esta vacia, el primer
          elemento del camino esta en la cima de c */
{
    pair<int,vector<int>> cami = i_cami_preferent(a);
    int n = cami.second.size();
    for(int i = 0; i < n; ++i)
    {
        c.push(cami.second[i]);
    }
}
/*
int main()
{
    stack<int> c;
    BinTree<int> a;
    read_bintree_int(a,0);
    cami_preferent(a,c);
    while (not c.empty())
    {
        cout << c.top() << ' ';
        c.pop();
    }
    cout << endl;
}*/
