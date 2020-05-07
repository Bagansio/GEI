#include <iostream>
#include <vector>
using namespace std;

vector<char> read(){
  char c;
  vector <char> v (0);
  while (cin >> c and c != '.'){
    if (c <= 'Z' and c >= 'A') v.push_back(c);
  }
  return v;
}
int pos_min(const vector<char>& v, int left, int right){
  int pos = left;
  for (int i = left + 1; i <= right; ++i){
    if(v[i] < v[pos]) pos = i;
  }
  return pos;
}

void sort(vector<char>& v){
  int last = v.size() - 1;
  for (int i = 0; i < last; ++i){
    int k = pos_min(v,i,last);
    swap(v[k],v[i]);
  }
}

bool compare (const vector <char>& v1, const vector <char>& v2){
  int n = v1.size();
  for (int i = 0; i < n; ++i){
    if (v1[i] != v2[i]) return false;
  }
  return true;
}

int main(){
  int c;
  cin >> c;
  for (int i = 0; i < c; ++i){
    vector <char> v1 = read();
    vector <char> v2 = read();
    sort(v1);
    sort(v2);
    if (compare(v1,v2)) cout << "YES";
    else cout << "NO";
    cout << endl;
  }
}
