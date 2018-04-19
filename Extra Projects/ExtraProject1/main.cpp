/******************************************************************************
* Course       : CS 2250 E01 (Fall 2015)
* Assignment   : Extra Project 1
* Summary      : Creates a DoubleLinked list and demonstrates its functions
* Author       : Ian Piskulic
* Last Modified: October 31, 2015
******************************************************************************/
#include "DoubleLink.h"
#include <time.h>
#include <stdlib.h>
#include <cctype>

/******************************************************************************
* Name    : main
* Purpose : To test out the other functions created.
* Inputs  : None
* Outputs : Returns 0 if ran successfully.
******************************************************************************/
int main()
{
  DoubleLink* list1 = new DoubleLink();
  srand(time(NULL));

  // Assigns 10 random numbers
  for (int i = 0; i < 10; i++)
  {
    list1->insert(rand() % 100 + 1);
  }

  // Displays and makes a copy of link
  cout << "List 1: ";
  list1->display();
  DoubleLink* list2 = new DoubleLink(*list1);

  // Adds 10 more numbers to the copy and displays it
  for (int i = 0; i < 10; i++)
  {
    list2->insert(rand() % 100 + 1);
  }

  cout << "List 2: ";
  list2->display();

  // Remove all numbers from first list in the copy, then display
  for (int i = 0; i < 10; i++)
  {
    list2->remove((*list1)[i]);
  }

  cout << "List 2: ";
  list2->display();

  // Deallocate both lists
  list1->~DoubleLink();
  list2->~DoubleLink();
  list1 = list2 = NULL;

  return 0;
}