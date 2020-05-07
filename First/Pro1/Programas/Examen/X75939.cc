#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Row;
typedef vector<Row> Matrix;


//pre: empty Matrix
//post: full Matrix
void read (Matrix& M){
    int n = M.size();
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> M[i][j];
        }
    }
}

bool isParchessi(const Matrix& m, int& up, int& down, int& left, int& right){
    up = down = left = right = 0;
    int n = m.size();
    bool parell = false;
    if (n % 2 == 0) {
        --n;
        parell = true;
    }
    for (int i = 0; i < n/2; ++i){
        int j = i + 1;
        int aux = 1;
        if (parell) aux = 0;
        while (j < n - aux - i){
            up += m[i][j];
            down += m[n - aux - i][j];
            left += m[j][i];
            right += m[j][n - aux - i];
            ++j;
        }
    }
    return (up == down and left == right);
}

int main(){
    int n;
    while (cin >> n){
        Matrix M (n, vector <int> (n));
        read(M);
        int up,down,left,right;
        if(isParchessi(M,up,down,left,right)) cout << "true: ";
        else cout << "false: ";
        cout << up << ' ' << down << ", " << left << ' ' << right << endl;
    }
}