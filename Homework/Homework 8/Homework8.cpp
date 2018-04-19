/*
******************************************************************************
* Course       : CS 2250 E01(Fall 2015)
* Assignment   : Homework 8
* Author       : Ian Piskulic
* Last Modified: December 11th, 2015
* *****************************************************************************

Review Questions and Excercises(Chapter 20):

4. A subtree is one branch of the tree from one node down.

7. root

11. inorder, preorder, and postorder

17. ** Attached as a picture

18. 3, 7, 9, 10, 12, 14, 18, 20, 22, 24, 30

22. True

23. True


Review Questions and Excercises(Chapter 12):

2. ios::app

5. By reference, because the streams value will not be saved outside the function.

19. false

24. binary

41. fstream places("places.txt", ios::in | ios::out);

53. True

66. * Change if (file) to if (!file)
    * Change ios::in to ios::out

70. * ios:in should be ios::out

*/

// Programming Challenge #1:

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  string fileName;
  fstream file;
  int lineCount = 0;

  // Get the file name
  cout << "Hello! What is the file name?: ";
  cin >> fileName;

  // Open and read the first 10 lines
  file.open(fileName, ios::in);
  while (file && lineCount < 10)
  {
    string line;
    getline(file, line);
    cout << line << endl;
    lineCount++;
  }

  // If entire file was less than 10 lines, display message
  if (lineCount < 10)
  {
    cout << endl << "ENTIRE FILE DISPLAYED";
  }

  return 0;
}