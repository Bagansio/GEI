int freq(const T& x) const
/* Pre: cert */
/* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
{
    return freq_r(primer_node,x);
}

int freq_r(node_arbreGen* m, const T& x) const
{
    int fr = 0;
    if (m != nullptr)
    {
        if (m->info == x) ++fr;
        int N = m->seg.size();
        for (int i = 0; i < N; ++i)
        {
            fr += freq_r(m->seg[i], x);
        }
    }
    return fr;
}