#include "NumDays.h"

NumDays::NumDays(int workedHours)
{
  hours = workedHours;
  days = hours / HOURS_IN_DAY;
}

int NumDays::getHours()
{
  return hours;
}

double NumDays::getDays()
{
  return days;
}

void NumDays::setHours(int workedHours)
{
  hours = workedHours;
  days = hours / HOURS_IN_DAY;
}

void NumDays::setDays(double workedDays)
{
  days = workedDays;
  hours = days * HOURS_IN_DAY;
}

NumDays NumDays::operator+(const NumDays num)
{
  int totalHours = hours + num.hours;
  NumDays output(totalHours);

  return output;
}

