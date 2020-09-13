void arb_sumes(Arbre<int> &asum) const
/* Pre: cert */
/* Post: l'arbre asum és l'arbre suma del p.i. */
{
    int suma;
    asum.primer_node =  suma_arb(primer_node, suma);
}


static node_arbre* suma_arb(node_arbre* node, int& suma) 
{
    if(node == nullptr)
    {
       suma = 0;
       return nullptr;
    }
    else
    {
        node_arbre* n = new node_arbre;
        
        n->info = node->info;
        n->segE = suma_arb(node->segE,suma);
        n->info += suma;
        n->segD = suma_arb(node->segD,suma);
        n->info += suma;

        suma = n->info;
        return n;
    }
}