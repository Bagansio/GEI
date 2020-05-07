#include "Estudiant.hh"
#include <vector>
using namespace std;


vector <int> read_v(int S)
{
    vector <int> v(S);
    for(int i = 0; i < S; ++i)
    {
        cin >> v[i];
        --v[i];
    }
    return v;
}

void read_notes(vector <double>& v)
{
    int n = v.size();
    for(int i = 1; i < n; ++i)
    {
        cin >> v[i];
    }
}

double mitja(const vector <double>& notes, const vector <int>& vs)
{
    int n = vs.size();
    double suma = 0;
    for (int i = 0; i < n; ++i)
    {
        suma += notes[vs[i]];
    }
    suma /= n;
    return suma;
}

void write(const vector <Estudiant>& v)
{
    int n = v.size();
    for (int i = 0; i < n; ++i)
    {
        v[i].escriure();
    }
}

int main(){
    int M,N,S;
    cin >> M >> N >> S;
    vector <int> vs = read_v(S);
    vector <Estudiant> v(M);
    for (int i = 0; i < M; ++i)
    {
        v[i].llegir();
        vector <double> notes(N);
        notes[0] = v[i].consultar_nota();
        read_notes(notes);
        v[i].modificar_nota(mitja(notes,vs));
    }
    write(v);
}