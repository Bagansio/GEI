#include <iostream>
#include <vector>
using namespace std;

int potencia(int x,int y){
    for (int i = 0; i < y; ++i) x *= x;
    return x;
}

int avalua(const vector<int>& P, int x){
    int n = P.size();
    int aux, sum = 0;
    for (int i = 0; i < n; ++i){
        aux = potencia(x,i);
        sum += P[i] * aux;
    }
    return sum;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> P(n);
        for (int i=0; i<n; ++i) cin >> P[i];
        int x;
        cin >> x;
        cout << avalua(P,x) << endl;
    }
}
