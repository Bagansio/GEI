T max_suma_cami() const
 /* Pre: el parametre implicit no es buit */
 /* Post: el resultat es la suma del cami de suma maxima del parametre implicit */
{
    return max_suma_cami_r(primer_node);
}

T max_suma_cami_r(const node_arbreGen* m) const
{
    T max = m->info;
    int N = m->seg.size();
    bool first = true;
    for (int i = 0; i < N; ++i)
    {
        if (m->seg[i] != nullptr)
        {
            T aux = max_suma_cami_r(m->seg[i]);
            if (first or (aux + m->info) > max)
            {
                max = aux + m->info;
                if (first) first = false;
            }
        }
    }
    return max;
}