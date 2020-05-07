#include <iostream>
#include <vector>
using namespace std;

struct manh {
  int x,y,distance;
};

vector<manh> read (int n,int x, int y){
  vector<manh> dist (n);
  for (int i = 0; i < n; ++i){
    int a,b;
    cin >> a >> b;
    dist[i].x = a;
    dist[i].y = b;
    a -= x;
    b -= y;
    if (a < 0) a *= -1;
    if (b < 0) b *= -1;
    a += b;
    dist[i].distance = a;
  }
  return dist;
}

int pos_min(const vector<manh>& v, int left, int right){
  int pos = left;
  for (int i = left + 1; i <= right; ++i){
    if(v[i].distance < v[pos].distance or (v[i].distance ==  v[pos].distance and v[i].x < v[pos].x)) pos = i;
  }
  return pos;
}

void sort(vector<manh>& dist){
  int last = dist.size() - 1;
  for (int i = 0; i < last; ++i){
    int k = pos_min(dist,i,last);
    swap(dist[k],dist[i]);
  }
}

void write (const vector<manh>& dist){
  int n = dist.size();
  int d = -1;
  for (int i = 0; i < n; ++i){
    if(d < dist[i].distance) {
      d = dist[i].distance;
      cout << "punts a distancia " << d << endl;
    }
    cout << dist[i].x << ' ' << dist[i].y << endl;
  }
}

int main(){
  int x,y,n;
  cin >> x >> y >> n;
  vector<manh> dist = read(n,x,y);
  sort(dist);
  write(dist);
}
