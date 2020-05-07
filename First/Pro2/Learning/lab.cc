#include "mapa.hh"
using namespace std;

Mapa start_game()
{
    Mapa mapa;
    cout << "Escribe un numero para elegir la zona donde quieres empezar:" << endl;
    cout << "1.Arriba izquierda" << endl    ;
    cout << "2.Arriba derecha" << endl;
    cout << "3.Abajo izquierda" << endl;
    cout << "4.Abajo derecha" << endl;
    int n;
    cin >> n;
    if (n == 2) mapa.modificar_mapa(1,8);
    else if (n == 3) mapa.modificar_mapa(8,1);
    else if (n == 4) mapa.modificar_mapa(8,8);
    mapa.write_mapa();
    return mapa;
}

bool consultar_fut(Mapa& mapa,int di, int dj)
{
    if (mapa.puede_avanzar(di,dj))
    {
        mapa.mover_pj(di,dj);
        return true;
    }
    return false;
}

void torn (Mapa& mapa)
{
    bool first = true;
    bool puede = false;
    int c = 0;
    while (not puede)
    {
        if (first)
        {
            cout << "Hacia donde quieres ir:" << endl;
            first = false;
        }
        if (c == 3){
            mapa.write_mapa();
            c == 0;
        }
        else cout << "Esa direccion no es posible di una nueva:" << endl;
        cout << "w. Arriba" << endl;
        cout << "s. Abajo" << endl;
        cout << "a. Izquierda" << endl;
        cout << "d. Derecha" << endl;
        char n;
        cin >> n;
        if (n == 'w') puede = consultar_fut(mapa,-1,0);
        else if(n == 's') puede = consultar_fut(mapa,1,0);
        else if(n == 'a') puede = consultar_fut(mapa,0,-1);
        else if (n == 'd') puede = consultar_fut(mapa,0,1); 
        ++c;
    }

}

int main(){
    Mapa mapa = start_game();
    while (mapa.posicio_pj() != '*')
    {
        torn(mapa); 
        mapa.write_mapa();   
    }
    cout << endl << endl << endl << "HAS GUANYAT UWU" << endl;
}