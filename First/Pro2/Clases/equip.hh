/////////////////////////////////////////////////////////////////////////
//*Aquest codi es fet a partir del exercici X88161 del jutge (sessio1)*//
/////////////////////////////////////////////////////////////////////////

#ifndef EQUIP	// per evitar errors de compilacio
#define EQUIP	// quan aquest fitxer s'inclou molts cops	

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Ranking{

    private:

    struct Equip{
        int id,pts,gf,gc; 
    };

    //pre entero n
    //post un ranking de equipos con su id correspondiente y las variables
    //id pts gf gc inicializadas en 0 
    vector<Equip> crear_ranking(int n){
        vector<Equip> ranking(n);
        for(int i = 0; i < n; ++i){
            ranking[i].id = i + 1;
            ranking[i].pts = 0;
            ranking[i].gf = 0;
            ranking[i].gc = 0;
        }
        return ranking;
    }

    static bool cmp(const Equip& a, const Equip& b){  //¿¿¿porque ha de ser static????
        if(a.pts == b.pts){
            if (a.gf - a.gc == b.gf - b.gc) return a.id < b.id;
            return  (a.gf - a.gc) > (b.gf - b.gc);
        }
        else return a.pts > b.pts;
    }


    public:

    vector <Equip> ranking;

    // Constructora
    //pre un numero natural > 0
    //post: crea un ranking de equipos
    Ranking (int n){
        ranking = crear_ranking(n);
    }

    //pre un ranking de equipos mayor que 0
    //post nos  ordena el ranking segun orden decreciente de pts, en caso de empate 
    // la diferencia más pequeña entre gf y gc y finalmente orden decreciente de id
    //dice por orden del ranking su id, pts, gf y gc
    void write(){
        sort(ranking.begin(),ranking.end(), cmp);
        int n = ranking.size();
        for (int i = 0; i < n; ++i){
            cout << ranking[i].id << ' ' << ranking[i].pts << ' ' << ranking[i].gf << ' ' << ranking[i].gc << endl;
        }
    }
};

#endif