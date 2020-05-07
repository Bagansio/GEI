#include <iostream>
#include <vector>
using namespace std;

struct Swimmer {
    string name;
    string country;
    string style;
    double time;
};

typedef vector<Swimmer> Competition;

void read_data(Competition& v) {
    int n = v.size();
    for (int i = 0; i < n; ++i){
        cin >> v[i].name >> v[i].country >> v[i].style >> v[i].time;
    }
}

int winner(const Competition& v, string style) {
    int n = v.size();
    int i = 0;
    bool first = true;
    int win = -1;
    while (i < n){
        if (v[i].style == style){
            if (first){
                first = false;
                win = i;
            }
            else if(v[win].time > v[i].time) win = i;
        }
        ++i;
    }
    return win;
}

int main() {
    int n;
    cin >> n;
    Competition v(n);
    read_data(v);
    string style;
    while (cin >>style){
        int i = winner(v,style);
        if (i == -1) cout << "Style " << style << " has not been run";
        else cout << "Winner " << style << ": " << v[i].name << ' ' << v[i].country << ' ' << v[i].time;
        cout << endl;
    }
}