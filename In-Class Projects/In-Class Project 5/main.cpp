#include "AcademicDate.h"

int main()
{
  AcademicDate* today = new AcademicDate();
  today->setDate(2015, 10, 20, "Today");

  today->display();
  cout << endl;

  if (today->isHoliday())
    cout << "Today is a holiday!!";
  else
    cout << "Today is not a holiday";

  return 0;
}