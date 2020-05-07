#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool compare(const string& s){
  int n = s.length();
  vector <char> open (0);
  for (int i = 0; i < n; ++i){
    char c = s[i];
    if (c == '(' or c == '[') open.push_back(c);
    else {
      int p = open.size();
      if (p == 0) return false;
      else if(c == ')') {
        if (open[p-1] == '(') open.pop_back();
        else return false;
      }
      else if(c == ']'){
        if (open[p-1] == '[') open.pop_back();
        else return false;
      }
    }
  }
  int p = open.size();
  return (p == 0);
}

int main(){
  string s;
  while (cin >> s){
    if(compare(s)) cout << "yes";
    else cout << "no";
    cout << endl;
  }
}
