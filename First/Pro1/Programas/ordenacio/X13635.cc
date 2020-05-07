#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Track {
  string artist, title, genre;
  int year;
};

bool comp(const Track &a, const Track &b) {
  if (a.artist < b.artist) return false;
  if (a.artist > b.artist) return true;
  if (a.year > b.year) return true;
  if (a.year < b.year) return false;
  if (a.title < b.title) return false;
  return true;
}

vector<Track> read_tracks(int n) {
  vector<Track> V(n);
  for(int i = 0; i < n; ++i){
    cin >> V[i].artist >> V[i].title >> V[i].genre >> V[i].year;
  }
  return V;
}

void print_track(const Track &t) {
  cout << t.artist;
  cout << " (" << t.year;
  cout << ") " << t.title << " (" << t.genre << ")" << endl;
}

int pos_min(const vector<Track>& v, int left, int right) {
  int pos = left;
  for(int i = left + 1; i <= right; ++i) {
    if (comp(v[pos],v[i])) pos = i;
  }
  return pos;
}

vector<Track> ordenar(vector<Track>& V, const vector<string>& O){
  int no = O.size();
  int nv = V.size();
  vector<Track> aux (0);
  for (int i = 0; i < nv - 1; ++i){
    int k = pos_min(V, i, nv - 1);
    swap(V[k], V[i]);
  }
  for (int i = 0; i < no; ++i){
    int j = 0;
    while (j < nv){
      if (V[j].genre == O[i]) aux.push_back(V[j]);
      ++j;
    }
  }
  return aux;
  }

int main() {
  int n;
  cin >> n;
  vector<Track> V = read_tracks(n);
  string s;
  vector <string> O (0);
  while(cin >> s){
    O.push_back(s);
  }
  V = ordenar(V,O);
  n = V.size();
  for (int i = 0; i < n; ++i) print_track(V[i]);
}
