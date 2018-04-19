// Programmer: Ian Piskulic
// Date: 8/25/15
// Purpose: To guess one of the numbers in the array as
// the program gives hints.

#include <iostream>
#include <cmath>

using namespace std;

// Function Prototypes

// Description: Gets distance to the closest integer in the array
// Pre: Takes in the array of possible solutions, the size of the array, and the guess
// Post: Returns the distance to the closest number in the array
int distanceToClosest(const int solutions[], int size, int guess);

// Description: Checks if the guess was right
// Pre: Takes in the distance and the last distance calculated
// Post: Returns a bool based off if the user guessed a correct number
bool checkGuess(int distance, int oldDistance);

int main()
{
  // Variables
  int guess = 0;
  int distance = 0;
  int oldDistance = 2000;
  bool hasWon = true;

  // Constants
  const int SIZE = 5;
  const int SOLUTIONS[SIZE]{ 97, 254, 545, 775, 988 };

  cout << "Hello, please try and guess one of my numbers between 1 and 1000." << endl;
  do
  {
    cout << "Please make a guess: ";
    cin >> guess;

    // Checks for an invalid number
    while (guess > 1000 || guess < 1)
    {
      cout << "Error! Guess must be between 1 and 1000." << endl;
      cout << "Please make a guess: ";
      cin >> guess;
    }

    // Calculates the distance to the closest number and checks for the correct solution
    distance = distanceToClosest(SOLUTIONS, SIZE, guess);
    hasWon = checkGuess(distance, oldDistance);
    oldDistance = distance;

  } while (hasWon); // Stops once the user guesses a correct number

  cout << "Success!" << endl;

  return 0;
}

// Function Definitions
int distanceToClosest(const int solutions[], int size, int guess)
{
  int distance = 1000;

  for (int i = 0; i < size; i++)
  {
    if (abs(solutions[i] - guess) < distance)
    {
      distance = abs(solutions[i] - guess);
    }

  }

  return distance;
}

bool checkGuess(int distance, int oldDistance)
{
  if (distance == 0)
  {

    return false;
  }

  else if (oldDistance > 1000)
  {
    cout << "I'm sorry, thats incorrect" << endl;

    return true;
  }

  else
  {

    if (distance > oldDistance)
    {
      cout << "Getting colder!!" << endl;
    }

    else if (distance < oldDistance)
    {
      cout << "Getting warmer!!" << endl;
    }

    else
    {
      cout << "Still the same." << endl;
    }

    return true;
  }

}