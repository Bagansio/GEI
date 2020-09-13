void trenat(Cua &c)
 /* Pre: p.i. = C1, c = C2 */
 /* Post: el p.i. passa a ser el resultat de trenar C1 i C2; c passa a ser buida */
{
    trenat_r(primer_node,c.primer_node);
    if (longitud <= c.longitud) ultim_node = c.ultim_node;
    c.primer_node = nullptr;
    c.ultim_node = nullptr;
    longitud += c.longitud;
    c.longitud = 0;
}

void trenat_r(node_cua* &m, node_cua* &n)
{
    if (m != nullptr and n != nullptr)
    {
            node_cua* aux = n->seguent;
            n->seguent = m->seguent;
            m->seguent = n;
            trenat_r(n->seguent,aux);
    }
    else if (m == nullptr and n != nullptr)
    {
        m = n;
    }
}