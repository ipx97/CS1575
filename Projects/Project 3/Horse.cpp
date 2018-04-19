#include "Horse.h"

Horse::Horse(string horseName, string jockeyName)
{
  name = horseName;
  jockey = jockeyName;
  srand(time(NULL));
  maxSpeed = rand() % 30 + 1;
  distanceTraveled = 0;
  racesWon = 0;
}

int Horse::getDistanceTraveled()
{
  return distanceTraveled;
}

string Horse::getName()
{
  return name;
}

string Horse::getJockey()
{
  return jockey;
}

int Horse::getRacesWon()
{
  return racesWon;
}

void Horse::wonRace()
{
  racesWon++;

  return;
}

void Horse::sentToGate()
{
  distanceTraveled = 0;

  return;
}

void Horse::runOneSecond()
{
  distanceTraveled += rand() % (maxSpeed + 1);

  return;
}

void Horse::displayHorse(double raceDistance)
{
  const int BARWIDTH = 30;
  double progress = distanceTraveled / raceDistance;

  cout << "[";
  int pos = BARWIDTH * progress;
  for (int i = 0; i < BARWIDTH; ++i)
  {
    if (i < pos) cout << "=";
    else if (i == pos) cout << ">";
    else cout << " ";
  }
  cout << "] " << getName() << ", riden by " << getJockey();
  cout.flush();
  cout << endl;

  return;
}