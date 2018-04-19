/* HOMEWORK #1
By: Ian Piskulic
Date: 8/28/15

Review Questions and Excercises:

3. On average, the linear search function will have to read half of the array.

5. The maximum number of comparisons it will make is log base 2 of 1000 which is almost 10

11. binary search

17. False

18. Answers Only:    
Linear Average -  25  250  5000  50000  5000000
Linear Max     -  50  500  10000  100000  10000000
Binary Max     -  log2(50)  log2(10000) log2(100000) log2(10000000)
*/


// Programming Challenge #2
#include <iostream>

using namespace std;

int main()
{
  const int tickets[10] = { 13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121 };
  int winner = 0;

  cout << "Welcome! Enter this week's winning lottery number: ";
  cin >> winner;
  
  // Checks if the number entered is valid
  while (winner > 99999 || winner < 0)
  {
    cout << "Invalid lottry number. Try again: ";
    cin >> winner;
  }

  // Looks for a matching ticket
  for each (int ticket in tickets)
  {
    if (ticket == winner)
    {
      cout << "YOU HAVE WON!!!" << endl;
      system("pause");

      return 0;
    }

  }

  cout << "You have lost..." << endl;

  return 0;
}



// Programming Challenge #6
#include <iostream>
#include <string>

using namespace std;

// Pre: Takes in an array of name and the number of names
// Post: n/a
// Description: Uses the selection sort algorithm to sort the names in the array
void selectionSort(string array[], int NUM_NAMES);

int main()
{
  const int NUM_NAMES = 20;
  string names[NUM_NAMES] = { "Collins, Bill", "Smith, Bart", "Allen, Jim",
    "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
    "Taylor, Terri", "Johnson, Jill",
    "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
    "James, Jean", "Weaver, Jim", "Pore, Bob",
    "Rutherford, Greg", "Javens, Renee",
    "Harrison, Rose", "Setzer, Cathy",
    "Pike, Gordon", "Holland, Beth" };

  selectionSort(names, NUM_NAMES);

  for each (string name in names)
  {
    cout << name << endl;
  }

  return 0;
}

void selectionSort(string array[], int NUM_NAMES)
{
  int startScan, minIndex;
  string minValue;

  for (startScan = 0; startScan < (NUM_NAMES - 1); startScan++)
  {
    // Assigns the starting point of the array to search
    minIndex = startScan;
    minValue = array[startScan];

    // Searches for the smallest number in the array
    for (int index = startScan + 1; index < NUM_NAMES; index++)
    {
      if (array[index] < minValue)
      {
        minValue = array[index];
        minIndex = index;
      }

    }

    // Moves the numbers
    array[minIndex] = array[startScan];
    array[startScan] = minValue;
  }

}

