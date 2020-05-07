#include <iostream>
using namespace std;
int main(){
    cout.setf(ios::fixed);
    cout.precision(4);
    double c, i, r, result, comp;
    int t;
    string it;
    cin >> c >> i >> t >> it;
    r= i/100;
    comp=1;
if (it=="simple"){
    result= (c+(t*(c*(i/100))));
    cout << result << endl;
}

else if (it=="compound"){
    for (int p=0; p<t; p++){
        comp*= (1+(r));
    if (it=="simple"){
        result= (c+(t*(c*(i/100))));
        cout << result << endl;
    }


    else if (it=="compound"){
        for (int p=0; p<t; p++){
            comp*= (1+(r));
        }

    cout << (c*comp) << endl;
}
    }

}
}
