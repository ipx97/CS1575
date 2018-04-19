#ifndef NUMDAYS_H
#define NUMDAYS_H

#include <iostream>
using namespace std;

class NumDays
{
  int hours;
  double days;
  const int HOURS_IN_DAY = 8;
public:
  NumDays(int workedHours);
  int getHours();
  double getDays();
  void setHours(int workedHours);
  void setDays(double workedDays);
  NumDays operator+(const NumDays num);
};

#endif // NumDays.h