/******************************************************************************
* Course       : CS 2250 E01 (Fall 2015)
* Assignment   : Project 3
* Summary      : Runs a horse race
* Author       : Ian Piskulic
* Last Modified: October 12, 2015
******************************************************************************/
#include "Horse.h"

/******************************************************************************
* Name    : main
* Purpose : To test out the other functions created.
* Inputs  : None.
* Outputs : Returns 0 if ran successfully.
******************************************************************************/
int main()
{
  int numOfHorses;
  int numOfRaces = 0;
  int raceLength;
  bool finished = false;

  // Gets how many horses are in the race
  cout << "Good day! ";
  do
  {
    cout << "How many horses are in this race?: ";
    cin >> numOfHorses;
    cin.ignore();
  } while (numOfHorses < 1);

  // Create and initialize all of the Horse objects
  Horse** horses = new Horse*[numOfHorses];
  for (int i = 0; i < numOfHorses; i++)
  {
    cout << endl;
    string horseName;
    cout << "What is horse #" << i + 1 << "'s name?: ";
    getline(cin, horseName);   

    string jockeyName;
    cout << "What is jockey #" << i + 1 << "'s name?: ";
    getline(cin, jockeyName);

    horses[i] = new Horse(horseName,jockeyName);
  }

  // Gets the race length
  do
  {
    cout << endl << "How long is the race? (100 or more): ";
    cin >> raceLength;
  } while (raceLength < 100);

  // Race loop
  do
  {
    Horse* winner = new Horse("temp", "temp");

    // Have the horses run one second
    cout << endl;
    for (int i = 0; i < numOfHorses; i++)
    {
      horses[i]->runOneSecond();
      horses[i]->displayHorse(raceLength);
    }

    // Check for a winner
    for (int i = 0; i < numOfHorses; i++)
    {
      int distance = horses[i]->getDistanceTraveled();
      if (distance >= raceLength)
      {
        finished = true;
        if (winner->getDistanceTraveled() < distance)
        {
          winner = horses[i];
        }
        else if (winner->getDistanceTraveled() == distance)
        {
          srand(time(NULL));
          int num = rand() % 2;
          if (num == 1)
          {
            winner = horses[i];
          }
        }
      }
    }

    winner->wonRace();

    // Ask for another second
    if (!finished)
    {
      char answer;

      do
      {
        cout << endl << "Ready for the next second? (y/n): ";
        cin >> answer;
        answer = tolower(answer);
      } while (answer != 'n' && answer != 'y');

      if (tolower(answer) == 'n')
        finished = true;
    }

    if (finished)
    {
      // Outputs the wins for each horse
      numOfRaces++;
      cout << endl;
      for (int i = 0; i < numOfHorses; i++)
      {
        cout << horses[i]->getName() << " won " << horses[i]->getRacesWon();
        cout << " of " << numOfRaces << " races" << endl;
      }

      // Asks for another race
      char decision;

      do
      {
        cout << endl << "Would you like to race again? (y/n): ";
        cin >> decision;
        decision = tolower(decision);
      } while (decision != 'n' && decision != 'y');

      // Resets variables
      if (tolower(decision) == 'y')
      {
        finished = false;
        for (int i = 0; i < numOfHorses; i++)
        {
          horses[i]->sentToGate();
        }
      }
      else
      {
        // Deallocates winner
        delete winner;
        winner = nullptr;
      }
    }

  } while (!finished);

  // Deallocates horses
  delete[]horses;
  horses = nullptr;

  return 0;
}