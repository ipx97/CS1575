/******************************************************************************
* Course       : CS 2250 E01 (Fall 2015)
* Assignment   : Project 1
* Summary      : Creates two arrays from a given array that was shuffled
and compares values between the two.
* Author       : Ian Piskulic
* Last Modified: September 16, 2015
******************************************************************************/
#include <iostream>
#include <time.h>
#include <array>
using namespace std;

/******************************************************************************
* Name    : printArray
* Purpose : To print out an array.
* Inputs  : An array and the size of that array.
* Outputs : None.
******************************************************************************/
void printArray(const int arr[], int size);
/******************************************************************************
* Name    : initializeArray
* Purpose : To assign values to an array
* Inputs  : An array and the size of that array.
* Outputs : None.
******************************************************************************/
void initializeArray(int arr[], int size);
/******************************************************************************
* Name    : shuffleArray
* Purpose : Shuffles the given array's elements
* Inputs  : An array and the size of that array.
* Outputs : Returns the pointer to the shuffled array.
******************************************************************************/
int* shuffleArray(int arr[], int size);
/******************************************************************************
* Name    : swap
* Purpose : Swaps two integers
* Inputs  : Two integer pointers
* Outputs : None.
******************************************************************************/
void swap(int* a, int* b);
/******************************************************************************
* Name    : createOddArray
* Purpose : To create an array of only the odd numbers from a given array.
* Inputs  : An array, its size, and the odd number array's size.
* Outputs : Returns the pointer to the odd numbered array.
******************************************************************************/
int* createOddArray(const int origArr[], int origSize, int &newSize);
/******************************************************************************
* Name    : createEvenArray
* Purpose : To create an array of only the even numbers from a given array.
* Inputs  : An array, its size, and the even number array's size.
* Outputs : Returns the pointer to the even numbered array.
******************************************************************************/
int* createEvenArray(const int origArr[], int origSize, int &newSize);
/******************************************************************************
* Name    : arrayWar
* Purpose : Compares two arrays to see which numbers are greater.
* Inputs  : Two arrays and their sizes.
* Outputs : None.
******************************************************************************/
void arrayWar(int* arr1, int size1, int* arr2, int size2);
/******************************************************************************
* Name    : sortArray
* Purpose : Uses selection sort to sort the given array
* Inputs  : An array and the size of that array.
* Outputs : None.
******************************************************************************/
void sortArray(int* arr, int size);

/******************************************************************************
* Name    : main
* Purpose : To test out the other functions created.
* Inputs  : None.
* Outputs : Returns 0 if ran successfully.
******************************************************************************/
int main()
{
  // Main Variables
  int size;
  int* arr = NULL;

  // Gets an array size and checks if it is valid
  cout << "Hello! What size of array would you like? (1-100): ";
  cin >> size;
  while (size > 100 || size < 1)
  {
    cout << endl << "Invalid array size. Enter a different array size (1-100): ";
    cin >> size;
  }

  // Initializes and outputs the array
  arr = new int[size];
  initializeArray(arr, size);
  cout << "Original Array: ";
  printArray(arr, size);

  // Creates a shuffled version of the array and outputs the shuffled version
  int* shuffledArr = shuffleArray(arr, size);
  cout << "Shuffled Array: ";
  printArray(shuffledArr, size);

  //Creates the odd and even arrays
  int oddSize, evenSize;
  int* oddArr = createOddArray(shuffledArr, size, oddSize);
  cout << "Odd Array: ";
  printArray(oddArr, oddSize);
  int* evenArr = createEvenArray(shuffledArr, size, evenSize);
  cout << "Even Array: ";
  printArray(evenArr, evenSize);

  // Compares two arrays element by element and outputs the larger of the two elements
  arrayWar(oddArr, oddSize, evenArr, evenSize);

  // Deallocates memory
  delete[]arr;
  delete[]oddArr;
  delete[]evenArr;
  evenArr = NULL;
  oddArr = NULL;
  arr = NULL;

  return 0;
}

void initializeArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    arr[i] = i;
  }

  return;
}

void printArray(const int arr[], int size)
{
  cout << "[";

  // Prints each element in the array
  for (int i = 0; i < size; i++)
  {
    cout << arr[i];
    if (i != size - 1)
    {
      cout << " ";
    }

  }

  cout << "]" << endl;

  return;
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int* shuffleArray(int arr[], int size)
{
  // Creates a copy of the array
  int* temp = new int[size];
  memcpy(temp, arr, size * sizeof(int));

  // Shuffles the new array
  srand(time(NULL));
  for (int i = size - 1; i > 0; i--)
  {
    int j = rand() % (i + 1);
    swap(&temp[i], &temp[j]);
  }

  return temp;
}

int* createOddArray(const int origArr[], int origSize, int &newSize)
{
  // Gets the number of odd integers
  newSize = origSize / 2;

  int* oddArr = new int[newSize];
  int count = 0;

  for (int i = 0; i < origSize; i++)
  {
    // Checks if the number is odd
    if (origArr[i] % 2 != 0)
    {
      oddArr[count] = origArr[i];
      count++;
    }

  }

  return oddArr;
}

int* createEvenArray(const int origArr[], int origSize, int &newSize)
{
  // Gets the number of even integers
  if (origSize % 2 == 0)
  {
    newSize = origSize / 2;
  }

  else
  {
    newSize = (origSize / 2) + 1;
  }

  int* evenArr = new int[newSize];
  int count = 0;

  for (int i = 0; i < origSize; i++)
  {
    // Checks if the number is even
    if (origArr[i] % 2 == 0)
    {
      evenArr[count] = origArr[i];
      count++;
    }

  }

  return evenArr;
}

void arrayWar(int* arr1, int size1, int* arr2, int size2)
{
  int* winners = NULL;
  int winnerArrSize;
  int maxNum = size1 + size2;

  // Finds the size of the winner array and creates it
  if (size1 <= size2)
  {
    winners = new int[size2];
    winnerArrSize = size2;
  }

  else
  {
    winners = new int[size1];
    winnerArrSize = size1;
  }

  // Compares the values of the two arrays
  for (int i = 0; i < winnerArrSize; i++)
  {
    // If the number is greater than the max, it is not allocated
    if (maxNum < arr1[i])
    {
      winners[i] = arr2[i];
    }

    else if (maxNum < arr2[i])
    {
      winners[i] = arr1[i];
    }

    else if (arr1[i] < arr2[i])
    {
      winners[i] = arr2[i];
    }

    else
    {
      winners[i] = arr1[i];
    }

  }

  // Prints out the array and sorts the array
  cout << "ArrayWar Winners: ";
  printArray(winners, winnerArrSize);
  sortArray(winners, winnerArrSize);

  // Deallocates memory
  delete[]winners;
  winners = NULL;

  return;
}

void sortArray(int* arr, int size)
{
  int i, j, minIndex, tmp;

  // Uses selection sort
  for (i = 0; i < size - 1; i++)
  {
    minIndex = i;
    for (j = i + 1; j < size; j++)
    {
      if (arr[j] < arr[minIndex])
      {
        minIndex = j;
      }

    }

    if (minIndex != i)
    {
      tmp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = tmp;
    }

  }

  // Prints out the sorted array
  cout << "Sorted Array: ";
  printArray(arr, size);

  return;
}