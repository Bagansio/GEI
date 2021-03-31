#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Board;
typedef vector<vector<bool>> Visited;

void print_board(Board& b, Visited& vis, vector<pair<int,int>>& q,char& c,int i , int j)
{
    int n = b.   size();
    int m = b[0].size();
    if(i >= 0 and j >= 0 and i < n and j < m and not vis[i][j] and b[i][j] != '#')
    {   //SI LA POSICION NO ES VALIDA O LA HEMOS VISITADO O ES UN '#' ACABAMOS LA FUNCION
        if(b[i][j] != '.') c = b[i][j];      //SI EL CARACTER DE LA POSICION i,j ES DIFERENTE A '.' ES EL NUEVO VALOR
        else q.push_back(make_pair(i,j));    //SINO LO ES LO METEMOS EN EL VECTOR A PRINTEAR
        vis[i][j] = true;                    //MARCAMOS LA POSICION COMO VISTA
        print_board(b,vis,q,c,i-1,j);        //NOS MOVEMOS PARA ABAJO
        print_board(b,vis,q,c,i+1,j);        //NOS MOVEMOS PARA ARRIBA
        print_board(b,vis,q,c,i,j-1);        //NOS MOVEMOS PARA IZQUIERDA
        print_board(b,vis,q,c,i,j+1);        //NOS MOVEMOS PARA DERECHA
    }
}

void print_board(Board& b)
{
    int n = b.   size();
    int m = b[0].size();

    Visited vis(n,vector<bool>(m,false));

    for(int i = 0; i < n; ++i)  //RECORREMOS LA MATRIZ
    {
        for(int j = 0; j < m; ++j) 
        {
            if(not vis[i][j] and b[i][j] != '#') //SI ES UNA POSICION PARA PRINTEAR
            {
                vector<pair<int,int>> q;         //CREAMOS EL VECTOR DE POSICIONES A PRINTEAR
                char c = ' ';                    //CREAMOS EL CHAR PARA SABER SI SE HA ENCONTRADO ALGUN CARACTER PARA MODIFICAR EL VALOR DEL RESTO
                print_board(b,vis,q,c,i,j);      //LLAMAMOS A LA FUNCION AUX
                if(c != ' ')                     //SI HEMOS ENCONTRADO UN NUEVO VALOR
                {
                    for(pair<int,int> pos : q)   //PINTAMOS POR CADA ELEMENTO DEL VECTOR CON ESE NUEVO VALOR
                    {
                        b[pos.first][pos.second] = c;
                    }
                }
            } 
        }
    }
}

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        Board b(n,vector<char>(m));
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j) cin >> b[i][j];
        }
        print_board(b);
        for(vector<char> row: b)
        {
            for(char x : row) cout << x;
            cout << endl;
        }
        cout << endl;
    }
}