#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct word{
  int c;
  string s;
};

bool cmp(const word& a, const word& b){
  if(a.c == b.c) return a.s < b.s;
  else return a.c > b.c;
}

void evaluate(vector <word> & f, string s){
  int n = f.size();
  word aux;
  aux.c = 1;
  aux.s = s;
  if (n > 0) {
    int i = 0;
    bool found = false;
    while (i < n and not found){
      if (f[i].s == s) {
        found = true;
        ++f[i].c;
      }
      ++i;
    }
    if (not found) f.push_back(aux);
  }
  else f.push_back(aux);
}

int main(){
  int n,k;
  while (cin >> n >> k){
    vector <word> frequency (0);
    for (int i = 0; i < n; ++i){
      string s;
      cin >> s;
      evaluate(frequency,s);
    }
    sort(frequency.begin(), frequency.end(), cmp);
    for (int i = 0; i < k; ++i){
      cout << frequency[i].s << endl;
    }
    cout << "----------" << endl;
  }
}
