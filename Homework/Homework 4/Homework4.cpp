/*
******************************************************************************
* Course       : CS 2250 E01 (Fall 2015)
* Assignment   : Homework 4
* Author       : Ian Piskulic
* Last Modified: October 8, 2015
******************************************************************************

Review Questions and Excercises (Chapter 13):

1. The class is the guidelines or blueprints on how to make the object. The instance of the class is the object with all the variables declared in the class.

4. The name of the function is getRadius and the name of the class is Circle.

7. Yes it is. Making a variable private makes it so that only the functions within the class can access that variable. 
It protects the variable from other functions outside of the class.

11. A default constructor is the constructor that is called when no constructor is specificically called.
You cannot have multiple default constructors otherwise the program won't know which one to use.

13. Yes its constructor is called when the object is created.

24. private

25. public

30. inline

51. false

75. *No semicolon after the class name
    *No constructor that will take '200' as an argument
    *bar.weight will give you an error since weight is a private member variable
    *The definition for setWeight should be inside of the class definition of Dumbell

*/

// Programming Challenge #3

#include "Car.h"

int main()
{
  Car vroom(2015, "Tesla");

  // Speed up five times
  for (int i = 0; i < 5; i++)
  {
    vroom.accelerate();
    cout << "Current speed: " << vroom.getSpeed() << endl;
  }

  cout << endl;

  //Slow down five times
  for (int i = 0; i < 5; i++)
  {
    vroom.brake();
    cout << "Current speed: " << vroom.getSpeed() << endl;
  }

  return 0;
}