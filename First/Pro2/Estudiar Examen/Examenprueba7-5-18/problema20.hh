//PROBLEMA 1

// Pre : p 6= nullptr , k ≥ 0
// Po s t : r e t o r n a un a p un ta do r a l node que e s t à k p o s i c i o n s més
// e n l l à de p a l a cadena o bé n u l l p t r s i no hi ha k o més nod e s
// a c o n t i n u a c i ó de p
static node* salta(node* p , int k )
{
    if (p == nullptr) return nullptr;
    if (k == 0) return p;
    return salta(p->seg, --k);
}

MySet galopar () const
{
    MySet<class T> set_galopar;
    set_galopar.ult = nullptr;
    
    if (primer == nullptr)
    {
        set_galopar.primer = nullptr;
    }
    else
    {
        node* n = new node; 
        n -> info = primer->info;
        node* aux = n; 
        int i = 1;
        while (aux != nullptr)
        {
            aux->seg = salta(aux,i);
            i *= 2;
            if (aux->seg == nullptr) set_galopar.ult = aux;
            aux = aux->seg;
        }
        set_galopar.primer = n;
    }
    
}


static double area_r(node* n)
{
    double area = 0:
    if (n != nullptr)
    {
        area = 1 + (area_r(n->esq) + area_r(n->dre))/2;
    }
    return area;
}