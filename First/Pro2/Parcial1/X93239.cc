#include <iostream>
#include <vector>
using namespace std;

 int comptatge_frontisses(const vector<int> &v)
 /* Pre: cert */
 /* Post: el resultat es el nombre d'elements frontissa de v */
 {
     int suma, resta, frontisses;
     suma = frontisses = resta = 0;
     int mida = v.size();
     for (int i = 1; i < mida; ++i) suma += v[i];
     for (int i = 0; i < mida; ++i)
     {
         if (v[i] == suma - resta) ++frontisses;
         resta += v[i];
         if (i != mida - 1) suma -= v[i+1];
     }
     return frontisses;
 }

 
/*
  int main(){
     int n;
     cin >> n;
     vector<int> v(n);
     for(int i = 0; i < n; ++i) cin >> v[i];
    cout <<comptatge_frontisses(v) << endl;
 }*/