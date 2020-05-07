#include <iostream>
#include <vector>
using namespace std;

typedef vector<bool> row;
typedef vector<row> Tablero;

//pre: vector vacio
//post: vector con los diferentes tamaños de los barcos
void tamanodebarcos(vector <int>& v){
    int m = v.size();
    for (int i = 0; i < m; ++i){
        cin >> v[i];
    }
}

void leer_tablero(Tablero& T){
    int m = T.size();
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < m; ++j){
        int a;
        cin >> a;
        if (a == 1) T[i][j] = true;
        else T[i][j] = false;
        }
    }
}

bool analizar_barco(const vector<int>& tambarcos, vector<bool>& aparecebarco,int c){
    int nbarcos = tambarcos.size();
    bool encontrado = false;
    bool esbarco = false;
    int i = 0;
    while (i < nbarcos and not encontrado){
        if (c == tambarcos[i]){
            esbarco = true;
            if (aparecebarco[i] == false){
            encontrado = true;
            aparecebarco[i] = true;
            } 
        }
        ++i;
    }
    if (esbarco and not encontrado) return false;
    return true;
}  

bool analizar_tablero(const Tablero& tablero, const vector<int>& tambarcos){
    int m = tablero.size(); //mida tablero
    int nbarcos = tambarcos.size(); //numero de barcos
    vector<bool> aparecebarco(nbarcos,false);
    for (int i = 0; i < m; ++i){
        int contadorx = 0;
        int contadory = 0;
        for (int j = 0; j < m; ++j){
            //fila por fila
            if (tablero[i][j] == 1) ++contadorx;
            else if (contadorx != 0) {
                if (not analizar_barco(tambarcos,aparecebarco,contadorx))return false;
                contadorx = 0;
            }
            //columna columna
            if (tablero[j][i] == 1) ++contadory;
            else if(contadory != 0) {
                if (not analizar_barco(tambarcos,aparecebarco,contadory))return false;;
                contadory = 0;
            }

            //diagonal
            if (j + i + 1 < m and m - i - j >= 0){
                if (tablero[j][j+i] and tablero[j+1][j+i+1]) {
                    return false;
                }
                if (tablero[j+i][j] and tablero[j+i+1][j+1]) {
                    return false;
                }
                if (tablero[j][m - i - j] and tablero[j+1][m - i - j - 1]) return false;
                if (tablero[j + i][m - j] and tablero[j+1+i][m - j - 1]) return false;
            }
        }
    }
    for (int i = 0; i < nbarcos; ++i){
        if (not aparecebarco[i]) return false;
    }
    return true;
}

int main(){
    int nbarcos;
    while (cin >> nbarcos and nbarcos != 0){
        vector <int> tambarcos(nbarcos);
        tamanodebarcos(tambarcos);
        int m; //tamaño tablero
        cin >> m;
        Tablero tablero(m,row(m));
        leer_tablero(tablero);
        if (analizar_tablero(tablero,tambarcos)) cout << "SI";
        else cout << "NO";
        cout << endl;
    }
    return 0;
}