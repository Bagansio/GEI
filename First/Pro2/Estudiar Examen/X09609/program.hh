void sub_arrel(Arbre& asub, const T& x)
 /* Pre: p.i. = A, asub es buit */
 /* Post: si A conte x, asub es el subarbre d'A resultat de la cerca;
    si A no conte x, asub es buit */
{
    int min_dist = -1;
    sub_arrel_rec(primer_node, asub.primer_node, x, 0, min_dist);
}

void sub_arrel_rec(node_arbre* m, node_arbre* & n, const T& x, int dist, int& min_dist)
{
    if (m != nullptr)
    {
        if (m->info == x and (dist <= min_dist or min_dist == -1))
        {
            min_dist = dist;
            n = copia_node_arbre(m);
        }
        sub_arrel_rec(m->segE, n, x, ++dist, min_dist);
        sub_arrel_rec(m->segD, n, x, ++dist, min_dist);
    }
}
/*
static node_arbre* sub_arrel_r(node_arbre* m, const T& x, int& distance)
{
    if (m == nullptr) return nullptr;
    node_arbre* n = new node_arbre;
    if (m->info == x)
    {
        distance = 1;
        n = copia_node_arbre(m);
    }
    else
    {
        int distD,distE;
        distD = distE = 0;
        n = sub_arrel_r(m->segE, x, distE);
        node_arbre* aux;
        aux = sub_arrel_r(m->segD,x,distD);
        if (distD < distE)
        { 
            n = aux;
            distance = distD + 1;
        }
        else distance = distE + 1;
    }
    return n;
}*/