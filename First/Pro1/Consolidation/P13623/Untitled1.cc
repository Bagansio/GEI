#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int LONG_ALFABET = 'z' - 'a' + 1;

char lletra_mes_frequent(const string& s) {
    vector <int> lmf(LONG_ALFABET, 0);
    int m = s.size();
    for (int i = 0; i < m; ++i) {
        ++lmf[s[i]-'a'];
    }
    int pos = 0, freq = 0;

	for (int i = 0; i < LONG_ALFABET; ++i) {
        if (lmf[i] > freq) {
            pos = i;
            freq = lmf[i];
        }
    }
    char c = 'a' + pos;
    return c;
}
int main(){
    cout.setf(ios::fixed);
    cout.precision(2);
    int n;
    while (cin >> n){
        vector<string> v(n);
        double media = 0;
        for (int i = 0; i < n; ++i){
            cin >> v[i];
            media += v[i].length();
        }
        media /= n;
        cout << media << endl;
        for (int i = 0; i < n; ++i){
            if (v[i].length() >= media) cout << v[i] << ": " << lletra_mes_frequent(v[i]) << endl;
        }
    }
}
