/******************************************************************************
* Course       : CS 2250 E01 (Fall 2015)
* Assignment   : In-Class Project 1
* Summary      : This program tests the reverseArray function
* Author       : Ian Piskulic
* Last Modified: September 8, 2015
******************************************************************************/
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