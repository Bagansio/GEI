#include <iostream>
#include <vector>
using namespace std;

struct Comida {
    int contador;
    double suma;
};

void evaluacion(vector<Comida>& v, char c,double a,double& comidas){
    if (c == 'D'){
        ++v[0].contador;
        v[0].suma += a;
        comidas += a;
    }   
    else if (c == 'A'){
        ++v[1].contador;
        v[1].suma += a;
        comidas += a;
    }
    else if (c == 'M'){
        ++v[2].contador;
        v[2].suma += a;
        comidas += a;
    }
    else if (c == 'I'){
        ++v[3].contador;
        v[3].suma += a;
        comidas += a;
    }
    else if (c == 'C'){
        ++v[4].contador;
        v[4].suma += a;
    }
}

void nombre(int c){
    if (c == 0) cout << "DESAYUNOS";
    else if (c == 1) cout <<"COMIDAS";
    else if (c == 2) cout << "MERIENDAS";
    else if (c == 3) cout << "CENAS";
    else if (c == 4) cout << "COPAS";
}

void declararvector(vector < Comida >& v){
    for (int i = 0; i < 5; ++i){
        v[i].contador = 0;
        v[i].suma = 0;
    }
}

void decir(const vector < Comida>& v){
    for (int i = 0; i < 5; ++i) cout << v[i].contador << ' ' << v[i].suma << endl;
}

int main(){
    char c;
    int contador = 0;
    double a;
    double ventas = 0;
    double comidas = 0;
    vector < Comida > v(5);
    declararvector(v);
    while (cin >> c >> a){
        ++contador;
        cout << contador;
        ventas += a;
        if (c != 'N') evaluacion(v,c,a,comidas);
        else {
            // decir(v);
            int contmax = 0;
            cout << 'h';
            while (contmax < 5 and v[contmax].contador == 0) {
                cout << contmax << endl;
                ++contmax;
            }
                double mediamax = v[contmax].suma / v[contmax].contador;
                double mediamin = mediamax;
                bool empatemax = false;
                bool empatemin = false;
                int i = contmax + 1;
                int contmin = contmax;
                cout << 'h';
                while (i < 5){
                    if (v[i].contador != 0) {
                        double mediaux = v[i].suma / v[i].contador;
                        if (mediaux > mediamax){
                            mediamax = mediaux;
                            contmax = i;
                            empatemax = false;
                        }
                        else if (mediaux == mediamax) empatemax = true; 
                        if (mediaux < mediamin) {
                            mediamin = mediaux;
                            contmin = i;
                            empatemin = false;
                        }
                        else if (mediaux == mediamin) empatemin = true; 
                        ++i;
                    } 
                }
                if (empatemax) cout << "EMPATE";
                nombre(contmax);
                cout << '#';
                if (empatemin) cout << "EMPATE";
                nombre(contmin);
                cout << '#';
                if (ventas/contador < comidas/(contador-v[4].contador)) cout << "SI";
                else cout << "NO";
                declararvector(v);
        }

        
    }
}