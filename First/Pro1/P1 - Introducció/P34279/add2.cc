#include <iostream>
using namespace std;

int main() {
    int hours, minutes, seconds;
    cin >> hours >> minutes >> seconds;

    	if (seconds == 59) {
            if (minutes == 59) {
                if (hours == 24) {
                    seconds = 00;
                    minutes = 00;
                    hours = 00;
			}
                else {
				seconds = 00;
				minutes = 00;
				hours = hours + 1;
			}
		}
            else {
			seconds = 00;
			minutes = minutes + 1;
		}
	}
        else {seconds = seconds + 1;}
    if (seconds == 0 and minutes == 0 and hours == 00) {
         cout << "00:00:00" << endl;
                }
    else {
	if (hours < 10) {
            cout << '0' << hours << ':';
	}
	else {cout << hours << ':';}

	if (minutes < 10) {
            cout << '0' << minutes << ':';
            }
	else {cout << minutes << ':';}

	if (seconds < 10) {
            cout << '0' << seconds << endl;
	}
	else {cout << seconds << endl;}
}
}

