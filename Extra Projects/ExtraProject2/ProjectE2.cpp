/******************************************************************************
* Course       : CS 2250 E01 (Fall 2015)
* Assignment   : Extra Project 2
* Summary      : This performs the game of life
* Author       : Ian Piskulic
* Last Modified: November 25, 2015
******************************************************************************/
#include "GameOfLife.h"
using namespace std;

/******************************************************************************
* Name    : main
* Purpose : This tests the functions of the GameOfLife class
* Inputs  : None.
* Outputs : Returns 0 if ran successfully.
******************************************************************************/
int main()
{
  // Loads the grid
  GameOfLife game(2, 2);
  game.loadGrid("input.txt");

  // Runs three generations
  game.oneGeneration();
  game.oneGeneration();
  game.oneGeneration();

  // Outputs the grid to the file
  game.writeGrid("output.txt");

  // Deallocate memory
  game.~GameOfLife();

  return 0;
}