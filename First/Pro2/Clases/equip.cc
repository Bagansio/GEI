#include "equip.hh"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/////////////////////////////////////////////////////////////////////////
//*Aquest codi es fet a partir del exercici X88161 del jutge (sessio1)*//
/////////////////////////////////////////////////////////////////////////
typedef vector < vector < pair <int,int> > > Matriu;

void llegir_matriu(Matriu& llista){
    int n = llista.size();
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> llista[i][j].first >> llista[i][j].second;
        }
    }
}

void analisis(const Matriu& llista,Ranking& rk){
    int n = rk.ranking.size(); //mida de les matrius i el vector
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i != j){
                //suma puntaciones de izq a derecha
                rk.ranking[i].gf += llista[i][j].first;
                rk.ranking[i].gc += llista[i][j].second;
                rk.ranking[j].gc += llista[i][j].first;
                rk.ranking[j].gf += llista[i][j].second;
                //suma punts. 
                                //esq dreta
                if (llista[i][j].first > llista[i][j].second){
                    rk.ranking[i].pts += 3;
                }
                else if (llista[i][j].first == llista[i][j].second){
                    ++rk.ranking[i].pts;
                    ++rk.ranking[j].pts;
                }
                else rk.ranking[j].pts += 3;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    Ranking rk(n);
    Matriu llista (n,vector < pair <int,int> > (n));
    llegir_matriu(llista);
    analisis(llista,rk);
    rk.write();
}
