// EXERCICI 1

void alliberar (int x );
/* Pre: x > 0. */
/* Post: Si el parametre impl ` ´ıcit (p.i .) contenia un bloc de memoria amb identificador ` x,
la memoria que ocupava el bloc amb identificador ` x ha estat alliberada y l' identificador x
ha deixat de ser valid, perqu ` e el p.i . ja no cont ` e un bloc de mem ´ oria amb identificador ` x. */
{
    Node* p = primer;
    while (p->seg != nullptr and p->seg->id != x) p = p->seg;
    if (p->seg != nullptr)
    {
        Node* aux = p->seg;
        p->seg = p->seg->seg;
        delete aux;
    }
}

int demanar(int b );
/* Pre: b > 0
/* Post: Si no hi ha b bytes consecutius lliures al p.i ., el resultat es´ −1; en un altre cas, es
reserva un bloc format pels primers b bytes consecutius lliures (es a dir , no reservats ) del p.i ., ´
se li assigna com a identificador el enter seguent a l ' ¨ ultim identificador assignat i es retorna ´
aquest identificador com a resultat . */
{
    Node* p = primer;
    Node *pseg;
    while(p->seg != nullptr and (p->seg->adreca - p->mida - p->adreca < b))
    {
        p = pseg;
        pseg = pseg-seg;
    }
    if (p->adreca + p->mida >= N) return -1;
    Node* aux = new node;
    ++darrer_id;
    if (pseg == nullptr)
    {
        aux->seg = nullptr;
    }
    else
    {
        aux->seg = pseg;
    }
    aux->id = darrer_id;
    aux->adreca = p->adreca + p->mida;
    aux->mida = b;
    p->seg = aux
    return darrer_id;
}




// EXERCICI 2