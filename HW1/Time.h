#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
      // Constructors
      Time();
      Time(int totalSeconds);
      Time(int hrs, int mnts);
      Time(int hrs, int mnts, int scnds);

      // Setters and Getters
      void setHours(int h);
      int getHours();
      void setMinutes(int m);
      int getMinutes();
      void setSeconds(int s);
      int getSeconds();

      //More Methods
      int toSecond();
      void fromSecond(int MaxSeconds);

      //Printing Functions
      void print();
      void printAmPm(); //AM/PM Printing
      void printTime();

      void next(int increment=1);

};


