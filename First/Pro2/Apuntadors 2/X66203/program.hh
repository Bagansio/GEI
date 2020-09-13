T maxim() const
/* Pre: el p.i. no és buit */
/* Post: el resultat indica el valor més gran que conté el p.i. */
{
    return max_r(primer_node, N);
}

static T max_r(node_arbreNari* m, int N) 
{
    //cout << 5 << endl;
    T max = m->info;
    for(int i = 0; i < N; ++i)
    {
        if (m->seg[i] != NULL)
        {
            T aux = max_r(m->seg[i],N);
            if (aux > max) max = aux;
        }

    }
    return max;
}
