node_llista* copia_node_llista_it (node_llista* m, node_llista* oact,
         node_llista* &u, node_llista* &a)
/* Pre: cert */
/* Post: si m és NULL, el resultat, u i a són NULL; en cas
       contrari, el resultat apunta al primer node d'una cadena de
       nodes que són còpia de la cadena que té el node apuntat per m
       com a primer, u apunta a l'últim node, a és o bé NULL si oact
       no apunta a cap node de la cadena que comença amb m o bé apunta
       al node còpia del node apuntat per oact */
{ 
    if (m == nullptr)
    {
        a = nullptr;
        u = nullptr;
        return nullptr;
    } 
    node_llista* n = new node_llista;
    n->info = m->info;
    n->ant = nullptr;
    n->seg = copia_node_llista_it(m->seg, oact, u, a);
    if (n->seg != nullptr) (n->seg)->ant = n;
    else u = n;
    if (m == oact) a = n;
    return n;
}



Llista& operator=(const Llista& original) 
    /* Pre: cert */
    /* Post: El p.i. passa a ser una còpia d'original i qualsevol
       contingut anterior del p.i. ha estat esborrat (excepte si el
       p.i. i original ja eren el mateix objecte) */
{
    if (primer_node != original.primer_node)
    {
        longitud = original.longitud;
        esborra_node_llista(primer_node);
        primer_node = copia_node_llista_it(original.primer_node,original.act,ultim_node,act);
    }
    return *this;
}