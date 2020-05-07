#include <iostream>
using namespace std;
int main() {
    int seconds, minutes, hours;
    cin >> hours >> minutes >> seconds;

    if (seconds == 59 or ( minutes == 0 and seconds == 0 and hours == 24)) {

        if (minutes == 59 or ( minutes == 0 and seconds == 0 and hours == 24)) {

            if (hours == 23 or ( minutes == 0 and seconds == 0 and hours == 24)) {

                hours = 0;
                minutes = 0;
                seconds = 0;
            }

            else {

                hours = hours+1;
                minutes = 0;
                seconds = 0;
        }
        }

        else {
            hours = hours;
            minutes = minutes+1;
            seconds =0;
        }
    }
    else {
        hours = hours;
        minutes = minutes;
        seconds = seconds+1;
    }

    if (hours<10) {

    cout << "0" << hours;
 }
    else {cout << hours;}

    if (minutes<10) {

    cout << ":0" << minutes;
    }

    else {cout << ":" << minutes;}

    if (seconds<10) {

        cout << ":0" << seconds << endl;
    }

    else {cout << ":" << seconds<< endl;}
}
