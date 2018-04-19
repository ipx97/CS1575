#ifndef DELIMITERSTACK_H
#define DELIMITERSTACK_H

#include <iostream>
using namespace std;

class DelimiterStack
{
  struct Node
  {
    char character;
    int lineNum;
    int charNum;
    Node* next;
  };
  Node* top; // Pointer to the top of the stack
  Node* createNode(int line, int delimNum, char delimiter);
public:
  /******************************************************************************
  * Name    : DelimiterStack
  * Purpose : To construct a stack object
  * Inputs  : None
  * Outputs : None
  ******************************************************************************/
  DelimiterStack();
  /******************************************************************************
  * Name    : ~DelimiterStack
  * Purpose : To deconstruct a stack object
  * Inputs  : None
  * Outputs : None
  ******************************************************************************/
  ~DelimiterStack();
  /******************************************************************************
  * Name    : push
  * Purpose : To push a delimiter to the stack
  * Inputs  : The line number and character number the delimiter is on and the
  delimiter itself
  * Outputs : None
  ******************************************************************************/
  void push(int lineNum, int delimiterNum, char delimiter);
  /******************************************************************************
  * Name    : pop
  * Purpose : To pop a Node from the stack
  * Inputs  : The contents of the popped node
  * Outputs : None
  ******************************************************************************/
  void pop(char &delim, int &line, int &elementNum);
  /******************************************************************************
  * Name    : isEmpty
  * Purpose : To tell if the stack is empty or not
  * Inputs  : None
  * Outputs : A bool telling if the stack is empty or not
  ******************************************************************************/
  bool isEmpty();
  /******************************************************************************
  * Name    : flipDelim
  * Purpose : To flip a delimiter the other way
  * Inputs  : A delimiter
  * Outputs : The delimiter flipped
  ******************************************************************************/
  char flipDelim(char delim);
};

#endif // DelimiterStack.h