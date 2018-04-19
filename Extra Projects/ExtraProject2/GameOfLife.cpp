#include "GameOfLife.h"
#include <fstream>
#include <iostream>


GameOfLife::GameOfLife(const int rowNum, const int colNum)
{
  rows = rowNum;
  cols = colNum;
  grid = new char*[rows];
  for (int i = 0; i < rows; i++)
    grid[i] = new char[cols];

  generation = 0;
}

GameOfLife::~GameOfLife()
{
  for (int i = 0; i < rows - 1; ++i)
    delete[] &grid[i];

  delete[] grid;
}

void GameOfLife::loadGrid(string input)
{
  const string delimiter = " ";
  ifstream inputFile(input);
  string line;

  // Gets the first line, and parses the number of rows and columns from it
  getline(inputFile, line, '\n');
  size_t pos = line.find(delimiter);
  string rowString = line.substr(0, pos);
  line.erase(0, pos + delimiter.length());
  string colString = line;
  rows = stoi(rowString);
  cols = stoi(colString);

  // Creates the GameOfLife object
  GameOfLife game(rows, cols);

  // Gets the grid from the file
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      inputFile >> game.grid[i][j];
    }
  }

  inputFile.close();
  *grid = *game.grid;
}

void GameOfLife::oneGeneration()
{
  generation++;

  // Loops through the 2d array
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      // Gets the number of neighbors
      int neighborCount = liveNeighborCount(i, j);

      // Applies game of life rules
      if (grid[i][j] == DEADCELL && neighborCount == 3)
        grid[i][j] = LIVECELL;
      else if (grid[i][j] == LIVECELL && neighborCount > 3)
        grid[i][j] = DEADCELL;
      else if (grid[i][j] == LIVECELL && neighborCount < 2)
        grid[i][j] = DEADCELL;
    }
  }
}

int GameOfLife::liveNeighborCount(int rowNum, int colNum)
{
  int liveCount = 0;

  if (isLiving(rowNum - 1,colNum - 1))
    liveCount++;
  if (isLiving(rowNum - 1, colNum))
    liveCount++;
  if (isLiving(rowNum - 1, colNum + 1))
    liveCount++;
  if (isLiving(rowNum, colNum - 1))
    liveCount++;
  if (isLiving(rowNum, colNum + 1))
    liveCount++;
  if (isLiving(rowNum + 1, colNum - 1))
    liveCount++;
  if (isLiving(rowNum + 1, colNum))
    liveCount++;
  if (isLiving(rowNum + 1, colNum + 1))
    liveCount++;

  return liveCount;
}

bool GameOfLife::isLiving(const int rowNum, const int colNum)
{
  if (rowNum >= 0 && rowNum < rows && colNum >= 0 && colNum < cols && grid[rowNum][colNum] == LIVECELL)
    return true;
  else
    return false;
}

void GameOfLife::writeGrid(string output)
{
  ofstream outputFile(output);

  // Writes the current generation to the file
  outputFile << "Generation: " << generation << endl;

  // Writes the grid to the file
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      outputFile << grid[i][j];
    }
    outputFile << endl;
  }

  outputFile.close();
}