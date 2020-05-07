#include <iostream>
using namespace std;

int main() {
    int years, days, hours, minutes, seconds;
    cin >> years >> days >> hours >> minutes >> seconds;
    cout << (years * 3600 * 24 *365) + (days * 3600 * 24) + (hours * 3600) + (minutes * 60) + seconds << endl;
}
