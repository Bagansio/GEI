#include "cjt_especies.hh"
using namespace std;


Cjt_especies::Cjt_especies()
{
}

Cjt_especies::~Cjt_especies(){}

void Cjt_especies::anadir_especie(string identificador, string gen)
{
    Conjunto[identificador] = gen;
}

void Cjt_especies::elimina_especie(string identificador)
{
    Conjunto.erase(identificador);
}

string Cjt_especies::obtener_gen(string identificador)
{
    return Conjunto[identificador];
}

bool Cjt_especies::existe_especie(string identificador)
{
    return Conjunto.find(identificador) != Conjunto.end();
}

void Cjt_especies::lee_cjt_especies()
{

    int n;
    cin >> n;
    map<string,string> Conjunto;    
    for (int i = 0; i < n; ++i)
    {
        string id,gen;
        cin >> id >> gen;
        Conjunto[id] = gen;
    }
    this->Conjunto = Conjunto;
}

void Cjt_especies::imprime_cjt_especies()
{
    for (map<string,string>::iterator it = Conjunto.begin(); it != Conjunto.end(); ++it)
    {
        cout << it->first << ' ' << it->second << endl;
    }
}

double Cjt_especies::distancia(string gen1,string gen2, int k)
{
    map<string,int> kmer1 = kmer(gen1,k);
    map<string,int> kmer2 = kmer(gen2,k);
    int max,min;
    max_min(kmer1,kmer2,max,min);
    cout << "max: " << max << "     " << "min: " << min << endl;
    return (1 - (double(min) / max)) * 100;
}


map<string,int> Cjt_especies::kmer(string gen,int k)
{
    int mida_gen = gen.length();
    map<string,int> kmer1;
    for (int i = 0; i <= mida_gen - k; ++i) 
    {
        string aux = gen.substr(i,k);       //crea un string aux hasta k posiciones desde i
        ++kmer1[aux];                       //poner el string aux en el map y si ya existe sumarle 1
    }
    return kmer1;
}

void Cjt_especies::max_min(map<string,int> kmer1, map<string,int> kmer2,int& max,int& min)
{
    max = min = 0;
    map<string,int>::iterator it1 = kmer1.begin();
    map<string,int>::iterator it2 = kmer2.begin();
    while (it1 != kmer1.end() and it2 != kmer2.end())
    {
        if (it1->first == it2->first)
        {
            if (it1->second > it2->second)
            {
                max += it1->second;
                min += it2->second;
            } 
            else
            { 
                max += it2->second;
                min += it1->second;
            }
            ++it1;
            ++it2;
        }
        else if (it1->first > it2->first)
        {
            max += it2->second;
            ++it2;
        }
        else
        {
            max += it2->second;
            ++it1;
        } 
    }
    map<string,int>::iterator end; 
    if (it1 == kmer1.end())
    { 
        end = kmer2.end();
        it1 = it2;
    }
    else end = kmer1.end();
    while (it1 != end)
    {
        max += it1->second;
        ++it1;
    }
}