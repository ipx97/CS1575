/*
******************************************************************************
* Course       : CS 2250 E01 (Fall 2015)
* Assignment   : Homework 2
* Author       : Ian Piskulic
* Last Modified: September 11, 2015
******************************************************************************

Review Questions and Excercises:

2. It will print out the value integer at the memory location iptr, which is 7

8. The code will stop working and break.

13. address

21. null

25. set + 7 = 99; ????????????????????????????????

26. arr = new int[20];
    for (int i = 0; i<20; i++)
    {
      cin >> arr[i];
    }

49. *Can't set x to null

52. *Outputs 13 and not 30

56. *Can't dereference something that is not a reference

60. *Can't return the address since the variable is a local variable

*/


// Programming Challenge #10

#include <iostream>
using namespace std;


/******************************************************************************
* Name    : reverseArray
* Purpose : This function reverses the elements an array
* Inputs  : An array and the size of that array
* Outputs : Returns the pointer to the new array
******************************************************************************/
int* reverseArray(const int arr[], int size);

/******************************************************************************
* Name    : main
* Purpose : This function tests the reverseArray function
* Inputs  : None.
* Outputs : Returns 0 if ran successfully.
******************************************************************************/
int main()
{
  const int SIZE = 5;
  int arr[SIZE] = { 4, 5, 6, 7, 8 };
  int* newArr = reverseArray(arr, SIZE);

  for (int i = 0; i < SIZE; i++) // Displays each element in the new array
  {
    cout << newArr[i] << endl;
  }

  return 0;
}

int* reverseArray(const int arr[], int size)
{
  int* newArr = new int[size];

  for (int i = 0; i < size; i++)
  {
    newArr[i] = arr[size - (i + 1)];
  }

  return newArr;
}