#include <iostream>
using namespace std;

int main () {

    int n,h,m,s;

    cin >> n ;

    cout << n/3600 << " " << (n%3600)/60 << " " << n-((n%3600)/60)-(n/3600) << endl;
}
