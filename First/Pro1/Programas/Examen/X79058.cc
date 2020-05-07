#include <iostream>
#include <vector>

using namespace std;

struct Things {
    string name;
    string color;
    string poison;
    string burns;
    double height;
};

typedef vector<Things> Forest;

void read_data(Forest& v) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        Things A;
        cin >> A.name >> A.color >> A.poison >> A.burns >> A.height;
        v.push_back(A);
    }
}

int count(const Forest& v, string name, string color,
          string poison, string burns, double height) {
    int c = 0;
    int n = v.size();
    for (int i = 0; i < n; ++i){
        if ((name == "*" or v[i].name == name) and (color == "*" or v[i].color == color) and (poison == "*" or v[i].poison == poison) and
        (burns == "*" or v[i].burns == burns) and height <= v[i].height) ++c;
    }
    return c;
}

int main() {
    Forest v;
    read_data(v);
    string n,c,p,b;
    double h;
    while(cin >> n >> c >> p >> b >> h){
    cout << count(v,n,c,p,b,h) << endl;
    }
}
