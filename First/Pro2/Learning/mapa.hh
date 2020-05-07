#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector <char> > Matrix;

class Mapa{

private:

    Matrix mapa;

    Matrix fer_mapa();

    int i;
    int j;
    const char form = '@';
    const char white = ' ';

public:

    //constructora;

    Mapa();

    Mapa(int i,int j);

    //Consultoras

    bool puede_avanzar(int di,int dj);
    
    char posicio_pj();
    
    //Modificadoras

    void modificar_mapa(int i, int j);

    void mover_pj(int di,int dj);
    //Int Out

    void write_mapa();



};