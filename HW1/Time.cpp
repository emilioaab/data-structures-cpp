#include "Time.h"

//Constructors - Methods
Time::Time() {
    hours = 23;
    minutes = 59;
    seconds = 59;
}

Time::Time(int totalSeconds) {
    hours = totalSeconds / 3600;
    minutes = (totalSeconds % 3600) / 60;
    seconds = (totalSeconds % 3600) % 60;
}

Time::Time(int hrs, int mnts) {
    if (hrs > 23 || mnts > 59 || hrs < 0 || mnts < 0) {
        hours = 0;
        minutes = 0;
        seconds = 0;
    } else {
        hours = hrs;
        minutes = mnts;
        seconds = 0;
    }
}

Time::Time(int hrs, int mnts, int scnds) {
    if (hrs > 23 || mnts > 59 || scnds > 59 || hrs < 0 || mnts < 0 || scnds < 0) {
        hours = 0;
        minutes = 0;
        seconds = 0;
    } else {
        hours = hrs;
        minutes = mnts;
        seconds = scnds;
    }
}

//setters getters
int Time::getHours() { return hours; }

void Time::setHours(int h) { hours = h; }

int Time::getMinutes() { return minutes; }

void Time::setMinutes(int m) { minutes = m; }

int Time::getSeconds() { return seconds; }

void Time::setSeconds(int s) { seconds = s; }


//Total
int Time::toSecond() {
    return hours * 3600 + minutes * 60 + seconds;
}

void Time::fromSecond(int MaxSeconds) {
    hours = MaxSeconds / 3600;
    minutes = (MaxSeconds % 3600) / 60;
    seconds = (MaxSeconds % 3600) % 60;
}

// hh:mm:ss print format
void Time::print() {

    cout << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes << ":"
         << (seconds < 10 ? "0" : "") << seconds;

}

void Time::printAmPm() {
    int amPmHours;
    amPmHours = hours % 12;
    if (amPmHours == 0) amPmHours = 12;

// Rounding up minutes if seconds are greater than or equal to 30
    int addedMinute = minutes;
    if (30 <= seconds) {
        addedMinute = (addedMinute + 1) % 60;
        if (addedMinute == 0)
            amPmHours = (amPmHours + 1) % 12;
    }

    // Adjusting the hours and AM/PM indicator based on the time
    string am_pm = (amPmHours < 12) ? "AM" : "PM";
    if (amPmHours == 0) {
        amPmHours = 12;
    } else if (amPmHours > 12) {
        amPmHours -= 12;
    }

    // Printing the time in the 12-hour format with AM/PM indicator
    cout << (amPmHours < 10 ? "0" : "") << amPmHours << ":" << (addedMinute < 10 ? "0" : "")
         << addedMinute << "_" << am_pm;
}

// Time(h:m:s) print format
void Time::printTime() {
    cout << "Time" << "(" << hours << "," << minutes << "," << seconds << ")";
}

void Time::next(int increment) {
    int totalSeconds = toSecond();
    totalSeconds += increment;
    totalSeconds %= (24 * 3600); // Add this line to ensure the total seconds wrap around to within 24 hours
    fromSecond(totalSeconds);
}

