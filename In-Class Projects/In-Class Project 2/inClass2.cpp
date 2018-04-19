/******************************************************************************
* Course       : CS 2250 E01 (Fall 2015)
* Assignment   : In-Class Project 2
* Summary      : This program tests the player info functions
* Author       : Ian Piskulic
* Last Modified: September 15, 2015
******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

struct PlayerInfo
{
  string name;
  int number;
  string position;
};

/******************************************************************************
* Name    : readPlayerInfo
* Purpose : This function reads in the player info
* Inputs  : A pointer to a PlayerInfo object
* Outputs : None.
******************************************************************************/
void readPlayerInfo(PlayerInfo* player);
/******************************************************************************
* Name    : displayPlayerInfo
* Purpose : Outputs the contents of the PlayerInfo object
* Inputs  : A PlayerInfo object
* Outputs : None.
******************************************************************************/
void displayPlayerInfo(const PlayerInfo player);
/******************************************************************************
* Name    : displayTeam
* Purpose : Displays the contents of an array of PlayerInfo objects
* Inputs  : An array of PlayerInfo objects and the size of that array
* Outputs : None.
******************************************************************************/
void displayTeam(const PlayerInfo* team, int size);

/******************************************************************************
* Name    : main
* Purpose : Tests the other functions in this program
* Inputs  : None.
* Outputs : Returns 0 if ran successfully.
******************************************************************************/
int main()
{
  const int SIZE = 3;
  PlayerInfo team[SIZE];

  // Reads in player info
  cout << "Hello! Lets create your team!" << endl;
  for (int i = 0; i < SIZE; i++)
  {
    readPlayerInfo(&team[i]);
  }

  // Outputs individual players to a function
  displayPlayerInfo(team[1]);
  displayPlayerInfo(team[0]);

  // Outputs the whole team to the console
  displayTeam(team, SIZE);

  return 0;
}

void readPlayerInfo(PlayerInfo* player)
{
  cout << endl << "What is the player's name?: ";
  cin >> player->name;
  cout << "What is the player's number?: ";
  cin >> player->number;
  cout << "What is the position of the player?: ";
  cin >> player->position;

  return;
}

void displayPlayerInfo(const PlayerInfo player)
{
  cout << endl << "Name: " << player.name << endl;
  cout << "Number: " << player.number << endl;
  cout << "Position: " << player.position << endl;

  return;
}

void displayTeam(const PlayerInfo* team, int size)
{
  for (int i = 0; i < size; i++)
  {
    displayPlayerInfo(team[i]);
  }

  return;
}