#include <iostream>
#include <vector>
using namespace std;


void i_solitaris(const vector<int> &v, int index, int& sols,bool previ)
{
    if (index < v.size() - 1)
    {
        if (v[index] != v[index + 1])
        {
            if (previ) ++sols;
            i_solitaris(v,index + 1, sols,true);
        }
        else i_solitaris(v,index + 1, sols,false);
    }
    else if (previ) ++sols;
}

 int solitaris(const vector<int> &v)
 /* Pre: v.size() > 0 */
 /* Post: el resultat es el nombre de solitaris a v */
 {
     int sols = 0;
    i_solitaris(v,0,sols,true);
     return sols;
 }

/*
 int main(){
     int n;
     cin >> n;
     vector<int> v(n);
     for(int i = 0; i < n; ++i) cin >> v[i];
    cout << solitaris(v) << endl;
 }*/