void push back(const T& x) {
/* Pre: El parametre impl ` ´ıcit es igual a la llista ´ {e1, . . . ,en}. */
/* Post: El parametre impl ` ´ıcit es igual a la llista ´ {e1, . . . ,en, x}. ✬ */
{
    Node* n = new node;
    n-> info = x;
    n->seg = nullptr;
    n->ant = ultim_node;
    if (primer_node == nullptr)
    {
        primer_node = n;
    }
    else
    {
        ultim_node->seg = n;
    }
    ultim_node = n;
    longitud += 1;
}

void interseccio ordenada (const Llista & c2) {
/* Pre: El parametre impl ` ´ıcit es igual a C1. C1 i c2 estan ordenades en ordre creixent ´
i no contenen elements repetits. */
/* Post: El parametre impl ` ´ıcit conte els elements de C1 que pertanyen a la intersecci ´ o´
de C1 i c2 en el mateix ordre en que estaven en C1. El punt d'inter ` es del par ` ametre `
impl´ıcit apunta al seu inici .
✬ */
{
    if (primer_node != nullptr)
    {
        if (c2.primer_node == nullptr) primer_node = nullptr;
        Node* n = primer_node;
        Node* aux = c2.primer_node;
        while(n != nullptr and aux != nullptr)
        {
            if (n->info > aux->info)
            {
                aux = aux->seg;
            }
            else if (n->info < aux->info)
            {
                Node* a = n;
                if (n != primer_node)
                {
                    n->ant->seg = n->seg;
                    n->seg->ant = n->ant
                }
                
                
                
                delete a;
                else
                {
                    primer_node = n->seg;
                }
                n = n->seg;
                delete a;
            }
        }
    }
}

bool poda subarbre(int x );
/* Pre: El parametre impl ` ´ıcit es un arbre binari A de enters. Els valors dels nodes de A ´
son tots diferents . ´ */
/* Post: Si x es el valor d'algun node de A, el resultat ´ es cert i el par ´ ametre impl ` ´ıcit es´
el resultat d'eliminar de A el node amb valor x i tots els seus descendents; altrament,
el resultat es fals i el par ´ ametre impl ` ´ıcit no varia (es a dir , ´ es A). ´ */
{
    bool p = false;
    primer_node = subarbre_R(primer_node,x,p);
    return p
}

static Node* subarbre_r(Node* m, int x,bool& p)
{
    if (m == nullptr)
    {
        return nullptr;
    } 
    Node* n = new node;
    if (m->info == x)
    {
        n = esborra_fills(m);
        p = true;
    } 
    else{
         n->info = m->info;
    n->segE = subarbre_r(m->segD,x,p);
    if(p == false)n->segD = subarbre_r(m->segE,x);
    }
   return n;
}

