bool buscar(const T& x) const
/* Pre: cert */
/* Post: el resultat indica si x es troba al p.i. o no */
{
    return  buscar_r(primer_node, x);
}

static bool buscar_r(node_arbreGen* m, const T& x)
{
    if (m != nullptr) 
    {
        if (m->info == x) return true;
        int N = m->seg.size();
        for (int i = 0; i < N; ++i)
        {
            if (buscar_r(m->seg[i],x)) return true;
        }
    }
    return false;
}