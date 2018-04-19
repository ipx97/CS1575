#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <string>
using namespace std;

class GameOfLife
{
  const char LIVECELL = 'X';
  const char DEADCELL = '.';
  int rows;
  int cols;
  int generation;
  char** grid;
  /******************************************************************************
  * Name    : GameOfLife
  * Purpose : Default constructor for the GameOfLife function
  * Inputs  : The amount of rows and the amount of columns in the grid
  * Outputs : None.
  ******************************************************************************/
  int liveNeighborCount(int rowNum, int colNum);
  /******************************************************************************
  * Name    : isLiving
  * Purpose : Default constructor for the GameOfLife function
  * Inputs  : The amount of rows and the amount of columns in the grid
  * Outputs : None.
  ******************************************************************************/
  bool isLiving(const int rowNum, const int colNum);
public:
  /******************************************************************************
  * Name    : GameOfLife
  * Purpose : Default constructor for the GameOfLife function
  * Inputs  : The amount of rows and the amount of columns in the grid
  * Outputs : None.
  ******************************************************************************/
  GameOfLife(const int rowNum = 0, const int colNum = 0);
  /******************************************************************************
  * Name    : ~GameOfLife
  * Purpose : Default destructor for the GameOfLife object
  * Inputs  : None.
  * Outputs : None.
  ******************************************************************************/
  ~GameOfLife();
  /******************************************************************************
  * Name    : loadGrid
  * Purpose : This function loads the grid from a text file
  * Inputs  : The directory of the file
  * Outputs : None.
  ******************************************************************************/
  void loadGrid(string input);
  /******************************************************************************
  * Name    : oneGeneration
  * Purpose : Runs the rules for the game of life one time.
  * Inputs  : None.
  * Outputs : None.
  ******************************************************************************/
  void oneGeneration();
  /******************************************************************************
  * Name    : writeGrid
  * Purpose : This outputs the grid to a text file
  * Inputs  : The directory of the file
  * Outputs : None.
  ******************************************************************************/
  void writeGrid(string output);
};

#endif // GameOfLife.h