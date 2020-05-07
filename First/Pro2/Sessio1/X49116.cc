 #include <vector>
 using namespace std;
 
 struct parint {int prim, seg;};
 
 parint max_min1(const vector<int>& v)
 /* Pre: v.size()>0 */
 /* Post: el primer componente del resultado es el valor maximo de v;
    el segundo componente del resultado es el valor minimo de v */
 {
     int n = v.size();
     parint maxmin;
     maxmin.prim = v[0];
     maxmin.seg = v[0];
     for (int i = 1; i < n; ++i){
         if (maxmin.prim < v[i]) maxmin.prim = v[i];
         if (maxmin.seg > v[i]) maxmin.seg = v[i];
     }
     return maxmin;
 }
 
 pair<int,int> max_min2(const vector<int>& v)
 /* Pre: v.size()>0 */
 /* Post: el primer componente del resultado es el valor maximo de v;
 el segundo componente del resultado es el valor minimo de v */
 {
     pair<int,int> a;
     a.first = v[0];
     a.second = v[0];
     int n = v.size();
     for (int i = 1; i < n; ++i){
         if (a.first < v[i]) a.first = v[i];
         if (a.second > v[i]) a.second = v[i];
     }
     return a;
 }
 
 void max_min3(const vector<int>& v, int& x, int& y)
 /* Pre: v.size()>0 */
 /* Post: x es el valor maximo de v;  y es el valor minimo de v */
 {
     x = v[0];
     y = v[0];
     int n = v.size();
     for (int i = 1; i < n; ++i){
         if (x < v[i]) x = v[i];
         if (y > v[i]) y = v[i];
     }
 }