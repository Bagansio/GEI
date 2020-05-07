#include "mapa.hh"

/* 
Necesito:
 -clase mapa formada per matriu mapa 
 -clase personatge
*/
const int mida = 10;

//constructoras

Mapa::Mapa(){
    mapa = fer_mapa(); 
    i = 1;
    j = 1;
    mapa[i][j] = form;

}

Mapa::Mapa(int i,int j)
{
    mapa = fer_mapa();
    this->i = i;
    this->j = j;
    mapa[i][j] = form;
}

Matrix Mapa::fer_mapa()
{
    Matrix mapa(mida,vector<char>(mida));
    for (int i = 0; i < mida;++i)
    {
        for (int j = 0; j < mida; ++j)
        {
            mapa[i][j] = ' ';
        }
    }
    for (int i = 0; i < mida; ++i)
    {
        mapa[0][i] = 'X';      //barrera arriba
        mapa[i][0] = 'X';      //barrera lateral izq
        mapa[mida-1][i] = 'X'; //barrera abajo
        mapa[i][mida-1] = 'X'; //barrera lateral drc
        if(i % 3 != 1)
        {
            mapa[2][i] = 'X';
            mapa[4][i] = 'X';
            mapa[5][i] = 'X';
        } 
    }
    mapa[3][3] = 'X';
    mapa[3][5] = 'X';
    for(int i = 0; i < 3; ++i)
    {
        mapa[i+6][i+2] = 'X';
        mapa[i+6][6-i] = 'X';
    }
    mapa[7][4] = '*';
    return mapa;
}

//Consultoras

bool Mapa::puede_avanzar(int di,int dj)
{
    int i = this->i + di;
    int j = this->j + dj;
    if (i >= 0 and j >= 0 and i < 10 and j < 10)
    {
        return (mapa[i][j] != 'X');
    }
}

char Mapa::posicio_pj()
{
    return mapa[i][j];
}



// Modificadoras

void Mapa::modificar_mapa(int i,int j)
{
    mapa[this->i][this->j] = white;
    this->i = i;
    this->j = j;
    mapa[this->i][this->j] = form;
}

void Mapa::mover_pj(int di,int dj)
{
    mapa[this->i][this->j] = white;
    this->i += di;
    this->j += dj;
    if (mapa[this->i][this->j] != '*')
    {
    mapa[this->i][this->j] = form;
    }
}

//Int OUt

void Mapa::write_mapa()
{
    for (int i = 0; i < mida; ++i)
    {
        for (int j = 0; j < mida; ++j)
        {
            cout << mapa[i][j];
        }
        cout << endl;
    }
}
