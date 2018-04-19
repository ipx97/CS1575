/******************************************************************************
* Course       : CS 2250 E01 (Fall 2015)
* Assignment   : In-Class Project 4
* Summary      : This program tests the functions in the integer array class
* Author       : Ian Piskulic
* Last Modified: October 6, 2015
******************************************************************************/
#include "IntegerArray.h"

int main()
{
  IntegerArray arr(20);

  arr.setElement(6, 10);
  cout << arr.getElement(6);

  arr.~IntegerArray();

  return 0;
}