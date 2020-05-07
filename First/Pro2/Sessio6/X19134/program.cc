#include "LlistaIOParInt.hh"
/*
int analitzar(int& c1, int& c2,list <ParInt>& l)
{
    c1 = 0;
    c2 = 0;
    int n;
    cin >> n;
    for (list<ParInt>::iterator i = l.begin(); i != l.end(); ++i)
    {
        ParInt aux = (*i);
        if (aux.primer() == n)
        {
            ++c1;
            c2 += aux.segon();
        }
    }
    return n;
}
*/
int main(){
    list<ParInt> l;
    LlegirLlistaParInt(l);
    int c1 = 0;
    int c2 = 0;
    int n;
    cin >> n;
    for (list<ParInt>::iterator i = l.begin(); i != l.end(); ++i)
    {
        ParInt aux = (*i);
        if (aux.primer() == n)
        {
            ++c1;
            c2 += aux.segon();
        }
    }
    cout << n <<' ' << c1 << ' ' << c2 << endl;
}

