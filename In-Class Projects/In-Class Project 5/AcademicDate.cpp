#include "AcademicDate.h"

AcademicDate::AcademicDate()
{
  current.day = 1;
  current.month = 1;
  current.year = 1970;

  // Initialize holidays
  int numOfHolidays = 5;
  holiday = new Date[numOfHolidays];
  Date* count = holiday;

  count = new Date(2015, 5, 25, "Memorial Day");
  count++;
  count = new Date(2015, 7, 4, "Independence Day");
  count++;
  count = new Date(2015, 9, 7, "Labor Day");
  count++;
  count = new Date(2015, 11, 26, "Thanksgiving");
  count++;
  count = new Date(2015, 12, 25, "Christmas");

}


AcademicDate::~AcademicDate()
{
  delete[]holiday;
  holiday = nullptr;
}

//Date AcademicDate::getDate() // Gives an error
//{
//  return current;
//}

void AcademicDate::setDate(int y, int m, int d, string desc)
{
  current.day = d;
  current.month = m;
  current.year = y;
  current.description = desc;
}

void AcademicDate::setHoliday(Date* newHolidays)
{
  holiday = newHolidays;
}

bool AcademicDate::isHoliday()
{
  bool output = false;
  for (int i = 0; i < numOfHolidays; i++)
  {
    Date* currentHoliday = holiday + 1;
    if ((currentHoliday->year == current.year) &&
      (currentHoliday->month == current.month) &&
      (currentHoliday->day == current.day))
    {
      output = true;
      break;
    }
  }

  return output;
}

void AcademicDate::display()
{
  cout << "The current date is " << this->current.month << "\\";
  cout << this->current.day << "\\" << this->current.year;
}

AcademicDate AcademicDate::operator+(const AcademicDate &input)
{
  AcademicDate* output = new AcademicDate();
  
  output->current.day = input.current.day + this->current.day;
  output->current.month = input.current.month + this->current.month;
  output->current.year = input.current.year + this->current.year;

  return *output;
}

AcademicDate::Date::Date(int y, int m, int d, string desc)
{
  year = y;
  month = m;
  day = d;
  description = desc;
}

AcademicDate::Date::Date()
{

}
