void  reorganitzar_in(const T& x)
/* Pre: p.i. = L */
/* Post: el p.i. conté els mateixos elements que L però
reorganitzats de manera que primer apareixen els més petits
o iguals que x, en el mateix ordre que en L, seguits pels 
més grans que x, en el mateix ordre que en L.
L'element actual del p.i. és el primer del més grans que x, si
existeix, sinó es situa a la dreta de tot */
{
    if(primer_node != nullptr)
    {
        if (primer_node->info <= x) act = nullptr;
        else
        {
            act = primer_node;
        }
        reorganitzar_r(x,primer_node->seg,act,ultim_node);
    }
}

void reorganitzar_r(const T& x,node_llista*& aux, node_llista* &act, node_llista* ultim)
{
    if (aux != nullptr)
    {
        cout << "pop" << endl;
        node_llista* a;
        if (aux == ultim) a = ultim;
        else a = aux->seg;
        if (aux->info <= x)
        {
            if ( act != nullptr)
            {
                if (aux == ultim)
                {
                    aux->ant->seg = nullptr;
                    act->ant->seg = aux;
                    aux->ant = act->ant;
                    aux->seg = act;
                    act->ant = aux;
                }
                else if (act->ant == nullptr)
                {
                    act->ant = aux;
                    aux->ant->seg = aux->seg;
                    aux->seg->ant = aux->ant;
                    aux->ant = nullptr;
                    aux->seg = act;

                    cout << aux -> seg->info << ' ' << endl;
                    cout << act -> ant ->info<< ' ' << endl;
                    cout << act -> seg->info << ' ' << endl;
                    cout << act -> seg -> ant ->info<< endl;
                 }
                else
                {
                    cout << aux->ant->seg;
                    act->ant->seg = aux;
                    cout << "CIO" << endl;
                    
                    aux->ant->seg = aux->seg;
                    cout << "CIO" << endl;
                    aux->seg->ant = aux->ant;
                    cout << "CIO" << endl;
                    aux->ant = act->ant;
                    cout << "CIO" << endl;
                    aux->seg = act;
                    cout << "CIO" << endl;
                    act->ant = aux;
                    cout << "CIO" << endl;
                }
            }
        }
        else if(act == nullptr) act = aux;
        if(a != ultim) reorganitzar_r(x,a,act,ultim);
    }
}