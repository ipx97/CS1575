/*
******************************************************************************
* Course       : CS 2250 E01 (Fall 2015)
* Assignment   : Homework 6
* Author       : Ian Piskulic
* Last Modified: November 1, 2015
******************************************************************************

Review Questions and Excercises (Chapter 18):

6. The stack wraps around the list container and uses its functions instead of the list's functions

14. push, pop

19. enqueue, dequeue

23. 

8 - top
19 - bottom

25. 

9 - front
12
10 - back

*/

// Programming Challenge #7:

#include "MathStack.h"

int main()
{
  MathStack stack(5);

  // Test the mult function
  stack.push(10);
  stack.push(2);
  stack.mult();

  // Test the div function
  stack.push(2);
  stack.div();

  // Test the addAll function
  stack.push(30);
  stack.push(20);
  stack.addAll();

  // Test the multAll function
  stack.push(2);
  stack.push(10);
  stack.multAll();

  return 0;
}

