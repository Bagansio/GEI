#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int DELTA_TIME = 10;  // space in minutes between samples

typedef struct {
  double magnitude;   // value of the peak
  int time;           // minutes from the origin (0 min.)
} Pic;

void llegir_mesures(vector<double> & vMesures) {
  int n = vMesures.size();
  for (int i = 0; i < n; ++i) cin >> vMesures[i];
}

// write the information of the pic p
void escriure_pic(const Pic& p) {
  cout << "(" << p.magnitude << "," << p.time << ")";
}

// returns the vector of peaks (<magnitude, time>)
vector<Pic> obte_pics(const vector<double> & vMesures) {
    vector<Pic> aux(0);
    int n = vMesures.size();
    for(int i = 1; i < n - 1; ++i){
        if(vMesures[i - 1] < vMesures[i] and vMesures[i] > vMesures[i + 1]){
            Pic a;
            a.magnitude = vMesures[i];
            a.time = i * 10;
            aux.push_back(a);
        }
    }
    return aux;
}

// returns true iff the peak p1 is "greater" than peak p2
bool compare(const Pic& p1, const Pic& p2) {
  if(p1.magnitude > p2.magnitude) return true;
  if(p1.magnitude < p2.magnitude) return false;
  if(p1.time < p2.time) return true;
  return false;
}

int main() {
  int n;
  while (cin >> n) {
    vector<double> vm(n);
    llegir_mesures(vm);
    vector<Pic> vp = obte_pics(vm);
    sort(vp.begin(),vp.end(),compare);
    int j,i;
    while (cin >> i >> j and (i != 0 or j != 0)){
        --i;
        --j;
        int a = vp.size();
        if (i < a and j < a){
        cout << '(' << vp[i].magnitude << ',' << vp[i].time << ")-(" << vp[j].magnitude << ',' << vp[j].time << ") : " << abs(vp[i].time - vp[j].time);
        }
        else cout << 'x';
        cout << endl;
    }
    cout << endl;
  }
}