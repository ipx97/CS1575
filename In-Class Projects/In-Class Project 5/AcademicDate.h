#ifndef ACADEMICDATE_H
#define ACADEMICDATE_H

#include <iostream>
#include <string>
using namespace std;

class AcademicDate
{
public:
  struct Date
  {
    int year;
    int month;
    int day;
    string description;
    Date(int y, int m, int d, string desc);
    Date();
  };
private:
  Date* holiday;
  Date current;
  int numOfHolidays;
public:
  AcademicDate();
  ~AcademicDate();
  Date getDate();
  void setDate(int y, int m, int d, string desc);
  void setHoliday(Date* newHolidays);
  bool isHoliday();
  void display();
  AcademicDate operator+(const AcademicDate &input);
};

#endif
