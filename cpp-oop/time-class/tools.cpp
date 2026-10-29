#include "tools.h"
#include "Time.h"
#include <iostream>
using namespace std;

void printRocketLanding(Time launchTime, Time airTime) {
    int totalSeconds = launchTime.toSecond() + airTime.toSecond();
    int days = totalSeconds / (24 * 3600);  // Calculate the number of days
    totalSeconds %= 24 * 3600;  // Remove the days from the total seconds

    Time landingTime;
    landingTime.fromSecond(totalSeconds);

    cout << "Landing time: ";
    if (days > 0) {
        cout << "[+" << days << "day],";
    }
    landingTime.print();
}


void printTimeDifference(Time time1, Time time2) {
    int seconds1 = time1.toSecond();
    int seconds2 = time2.toSecond();
    int diffSeconds = abs(seconds1 - seconds2);

    cout << "Time difference: " << diffSeconds;

    Time diffTime(diffSeconds);
    cout << " / ";
    diffTime.print();
}

void printSort(int num1, int num2) {
    if (num1 > num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    cout << "Sorted numbers: " << num1 << " | " << num2 << endl;
}

void printSort(int num1, int num2, int num3) {
    if (num1 > num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    if (num2 > num3) {
        int temp = num2;
        num2 = num3;
        num3 = temp;
    }
    if (num1 > num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    cout << "Sorted numbers: " << num1 << " | " << num2 << " | " << num3 << endl;
}

void printSort(Time time1, Time time2) {
    int seconds1 = time1.toSecond();
    int seconds2 = time2.toSecond();

    cout << "Sorted times: ";
    if (seconds1 > seconds2) {
        time2.print();
        cout << " | ";
        time1.print();
    } else {
        time1.print();
        cout << " | ";
        time2.print();
    }
    cout << endl;
}

void printSort(Time time1,Time time2, Time time3) {
    int seconds1 = time1.toSecond();
    int seconds2 = time2.toSecond();
    int seconds3 = time3.toSecond();

    cout << "Sorted times: ";
    if (seconds1 > seconds2) {
        if (seconds2 > seconds3) {
            time3.print();
            cout << " | ";
            time2.print();
            cout << " | ";
            time1.print();
        } else {
            if (seconds1 > seconds3) {
                time2.print();
                cout << " | ";
                time3.print();
                cout << " | ";
                time1.print();
            } else {
                time2.print();
                cout << " | ";
                time1.print();
                cout << " | ";
                time3.print();
            }
        }
    } else {
        if (seconds1 > seconds3) {
            time3.print();
            cout << " | ";
            time1.print();
            cout << " | ";
            time2.print();
        } else {
            if (seconds2 > seconds3) {
                time1.print();
                cout << " | ";
                time3.print();
                cout << " | ";
                time2.print();
            } else {
                time1.print();
                cout << " | ";
                time2.print();
                cout << " | ";
                time3.print();
            }
        }
    }
    cout << endl;
}