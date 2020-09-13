pop_and_stop(const T& x)
{
   nodo* aux = pop_and_stop_r(cima,x);
   if (aux != nullptr) cima = aux;
}

static nodo* pop_and_stop_r(nodo*& m,x);
{
    if (m == nullptr) return nullptr;
    if (m->info == x) return m;
    nodo* aux = pop_and_stop_r(m->sig,x);
    if(aux != nullptr) delete m;
    return aux;
}