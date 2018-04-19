/*
******************************************************************************
* Course       : CS 2250 E01 (Fall 2015)
* Assignment   : Homework 3
* Author       : Ian Piskulic
* Last Modified: September 22, 2015
******************************************************************************

Review Questions and Excercises (Chapter 10):

1. <cctype.h>

3.  c = toupper('a'); ____'A'____
    c = toupper('B'); ____'B'____
    c = tolower('D'); ____'d'____
    c = toupper('e'); ____'E'____ 

27. if (tolower(choice) == 'y')

32. #include <string.h>

    if (str1 == str2)
    {
      cout << "They are the same!"
    }

43. * isupper only works with characters
    * isupper only checks if the character is uppercase. It does not change the character.
    * isupper returns an int, not a string.

Review Questions and Excercises (Chapter 11):

  4. a. Point center;
     b. center.x = 12;
     c. center.y = 7;
     d. cout << "Center: " << center.x << "," << center.y;

  7. a. "Canton"
     b. "Haywood"
     c. 9478
     d. value is unknown

  8. a. r = new Rectangle;
     b. r->length = 10;
        r->width = 14;

  10. 8 bytes

  12. 0 1 2

  30. strPtr->num = 10;

  31. union Items
      {
        char alpha
        int num;
        long bigNum;
        float real;
      }
      Items i;

  34. a. Color
      b. RED,ORANGE,GREEN,BLUE
      c. Color lime = GREEN;

  59. *An object named TwoVals is never declared in main

  66. *Replace TwoVals with ThreeVals in main
      *Replace *sptr.a with sptr->a

*/

// Programming Challenge #5
#include <iostream>
#include <string>
using namespace std;

enum Month { JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };

struct WeatherData
{
  int totalRain;
  int highTemp;
  int lowTemp;
  int averageTemp;
};

/******************************************************************************
* Name    : getTemp
* Purpose : This gets the temperature from the user and checks it for errors
* Inputs  : None.
* Outputs : Returns the temperature
******************************************************************************/
int getTemp();

/******************************************************************************
* Name    : main
* Purpose : This functions iterates through the months and grabs weather data
* Inputs  : None.
* Outputs : Returns 0 if ran successfully.
******************************************************************************/
int main() 
{
  int totalRainfall = 0;
  WeatherData months[12];
  
  // Iterates through the months
  for (int i = JANUARY; i <= DECEMBER; i++)
  {
    cout << "What was the weather like for month #" << i + 1 << "?:\n\n";
    cout << "What was the total rainfall?: ";
    cin >> months[i].totalRain;
    cout << "What was the highest temperature this month?: ";
    months[i].highTemp = getTemp();
    cout << "What was the lowest temperature this month?: ";
    months[i].lowTemp = getTemp();
    cout << "What was the average temperature this month?: ";
    months[i].averageTemp = getTemp();
    cout << endl;
  }

  // Counts up the total rainfall
  for (int i = JANUARY; i <= DECEMBER; i++)
  {
    totalRainfall += months[i].totalRain;
  }

  // Output the average rainfall per month and total rainfall
  cout << "\n\nThe total rainfall for the year was: " << totalRainfall << endl;;
  cout << "The average rainfall per month this year was: " << totalRainfall / 12 << endl;

  return 0;
}

int getTemp()
{
  int temp;
  cin >> temp;

  while (temp > 140 || temp < -100)
  {
    cout << "Invalid tempurature. Try again: ";
    cin >> temp;
  }

  return temp;
}