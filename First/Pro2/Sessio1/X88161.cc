#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Equip{
    int posicio,punts,golsfavor,golscontra;
};

typedef vector<vector< pair<int,int> > > Matriu;

void llegir_matriu(Matriu& clasificacio){
    int n = clasificacio.size();
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> clasificacio[i][j].first >> clasificacio[i][j].second;
        }
    }
}

void analisis(const Matriu& clasificacio,vector<Equip>& ranking){
    int n = ranking.size(); //mida de les matrius i el vector
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i != j){
                //suma puntaciones de izq a derecha
                ranking[i].golsfavor += clasificacio[i][j].first;
                ranking[i].golscontra += clasificacio[i][j].second;
                ranking[j].golscontra += clasificacio[i][j].first;
                ranking[j].golsfavor += clasificacio[i][j].second;
                //suma punts. 
                                //esq dreta
                if (clasificacio[i][j].first > clasificacio[i][j].second){
                    ranking[i].punts += 3;
                }
                else if (clasificacio[i][j].first == clasificacio[i][j].second){
                    ++ranking[i].punts;
                    ++ranking[j].punts;
                }
                else ranking[j].punts += 3;
            }
        }
    }
}

bool cmp(const Equip& a, const Equip& b){
    if(a.punts == b.punts){
        if (a.golsfavor - a.golscontra == b.golsfavor - b.golscontra) return a.posicio < b.posicio;
        return  (a.golsfavor - a.golscontra) > (b.golsfavor - b.golscontra);
    }
    else return a.punts > b.punts;
}

vector<Equip> crear_ranking(int n){
    vector<Equip> ranking(n);
    for(int i = 0; i < n; ++i){
        ranking[i].posicio = i + 1;
        ranking[i].punts = 0;
        ranking[i].golsfavor = 0;
        ranking[i].golscontra = 0;
    }
    return ranking;
}

void write(const vector<Equip>& ranking){
    int n = ranking.size();
    for (int i = 0; i < n; ++i){
        cout << ranking[i].posicio << ' ' << ranking[i].punts << ' ' << ranking[i].golsfavor << ' ' << ranking[i].golscontra << endl;
    }
}

int main(){
    int n;
    cin >> n;
    vector<Equip> ranking = crear_ranking(n);
    Matriu clasificacio(n,vector < pair <int,int> > (n));
    llegir_matriu(clasificacio);
    analisis(clasificacio,ranking);
    sort(ranking.begin(),ranking.end(), cmp);
    write(ranking);
}