#ifndef HORSE_H
#define HORSE_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cctype>
using namespace std;

class Horse
{
  string name;
  string jockey;
  int maxSpeed;
  int distanceTraveled;
  int racesWon;
public:
  /******************************************************************************
  * Name    : Horse
  * Purpose : To construct a Horse object
  * Inputs  : The horse's name and the jockey's name
  * Outputs : None
  ******************************************************************************/
  Horse(string horseName, string jockeyName);
  /******************************************************************************
  * Name    : getDistanceTraveled
  * Purpose : To return the distanceTraveled for a Horse object
  * Inputs  : None.
  * Outputs : Returns distanceTraveled
  ******************************************************************************/
  int getDistanceTraveled();
  /******************************************************************************
  * Name    : getName
  * Purpose : To return the name for a Horse object
  * Inputs  : None.
  * Outputs : Returns name
  ******************************************************************************/
  string getName();
  /******************************************************************************
  * Name    : getJockey
  * Purpose : To return the jockey for a Horse object
  * Inputs  : None.
  * Outputs : Returns jockey
  ******************************************************************************/
  string getJockey();
  /******************************************************************************
  * Name    : getRacesWon
  * Purpose : To return the racesWon for a Horse object
  * Inputs  : None.
  * Outputs : Returns racesWon
  ******************************************************************************/
  int getRacesWon();
  /******************************************************************************
  * Name    : wonRace
  * Purpose : To add one to the racesWon member
  * Inputs  : None.
  * Outputs : None.
  ******************************************************************************/
  void wonRace();
  /******************************************************************************
  * Name    : runOneSecond
  * Purpose : Adds a random amount between 1 and the max speed to distance traveled
  * Inputs  : None.
  * Outputs : None.
  ******************************************************************************/
  void runOneSecond();
  /******************************************************************************
  * Name    : sentToGate
  * Purpose : Resets distanceTraveled to 0
  * Inputs  : None.
  * Outputs : None.
  ******************************************************************************/
  void sentToGate();
  /******************************************************************************
  * Name    : displayHorse
  * Purpose : Displays the current place in the race for the horse
  * Inputs  : The length of the race
  * Outputs : None.
  ******************************************************************************/
  void displayHorse(double raceDistance);
};

#endif // Horse.h
