void arbsuma(ArbreNari& asum) const
/* Pre: cert */
/* Post: asum és un arbre amb la mateixa estructura que el p.i.
         i cada node és la suma del node corresponent al p.i
         i tots els seus descendents al p.i. */
{
    asum.primer_node = suma_arb_r(primer_node,N);
}

static node_arbreNari* suma_arb_r(node_arbreNari* m, int N)
{
    if (m == nullptr)
    {
        return nullptr;
    }
    else
    {
        node_arbreNari* n = new node_arbreNari;
        n->info = m->info;
        n->seg = vector<node_arbreNari*> (N);
        for(int i = 0; i < N; ++i)
        {
         n->seg[i] = suma_arb_r(m->seg[i],N);
         if (n->seg[i] != nullptr) n->info += n->seg[i]->info;   
        }
        return n;
    }

}