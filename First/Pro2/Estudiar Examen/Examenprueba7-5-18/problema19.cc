// Pre : p != n u l l p t r
// P o s t : r e t o r n a n u l l p t r s i cap node e n t r e e l s u c c e s o r de p
// i e l f i n a l c o n t ´e x , a l t r a m e n t r e t o r n a un a p u n t a d o r a l
// p r e d e c e s s o r d ’ un node , e n t r e e l s u c c e s s o r de p i e l f i n a l ,
// que c o n t ´e x
static node * cerca ( node * p , const T & x );
{
    if (p == nullptr) return nullptr;
    if (p ->info == x) return p;
    return cerca(p->seg,x);
}