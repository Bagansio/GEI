#include <iostream>
#include <vector>
using namespace std;

const int ABC = 26;

int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i){
    vector<int> alpha(ABC,0);
    char c;
    while (cin >>c and c != '.'){
      if (c <= 'Z' and c >= 'A') ++alpha[c - 'A'];
    }
    while (cin >>c and c != '.'){
      if (c <= 'Z' and c >= 'A') --alpha[c - 'A'];
    }
    int j = 0;
    bool found = false;
    while (not found and j < ABC){
      if (alpha[j] != 0) found = true;
      else ++j;
    }
    if (found) cout << "NO";
    else cout << "YES";
    cout << endl;
  }
}
