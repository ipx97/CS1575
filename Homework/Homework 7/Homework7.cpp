/*
******************************************************************************
* Course       : CS 2250 E01(Fall 2015)
* Assignment   : Homework 7
* Author       : Ian Piskulic
* Last Modified: November 18, 2015
* *****************************************************************************

Review Questions and Excercises(Chapter 19):

1.
  12: num <= 0
  13: num > 0
  14: pos < size

3. Recursion is less efficent because it makes multiple calls to the stack and has to return each of the function calls.

6. depth

7. base case

10. 

int numCount(const int* arr, int num)
{
  if (!*arr)
    return 0;

  return (*arr == num) + numCount(arr + 1, num);
}

14. olleH


*/

// Programming Challenge #9:

#include <iostream>
#include <string>
using namespace std;

void stringFlip(string str, int pos, int size);

int main()
{
  string test = "flipper";

  stringFlip(test, 0, test.size());

  return 0;
}

void stringFlip(string str, int pos, int size)
{
  if (pos < size)
  {
    stringFlip(str, pos + 1, size);
    cout << str[pos];
  }
}
