#include "DelimiterStack.h"


DelimiterStack::DelimiterStack()
{
  top = nullptr;
}

DelimiterStack::~DelimiterStack()
{
  Node* ptr = nullptr, *nextNode = nullptr;
  ptr = top;

  while (ptr != nullptr)
  {
    nextNode = ptr->next;
    delete ptr;
    ptr = nextNode;
  }
}

void DelimiterStack::push(int lineNum, int delimiterNum, char delimiter)
{
  Node* newNode = createNode(lineNum, delimiterNum, delimiter);
  
  if (isEmpty())
  {
    top = newNode;
    newNode->next = nullptr;
  }
  else
  {
    newNode->next = top;
    top = newNode;
  }

  // Checks if the newNode was successfully pushed
  if (top != newNode)
    throw "ERROR: Not enough memory for this node";
}

void DelimiterStack::pop(char &delim, int &line, int &elementNum)
{
  if (!isEmpty())
  {
    delim = top->character;
    line = top->lineNum;
    elementNum = top->charNum;
    Node* nextNode = top->next;
    delete top;
    top = nextNode;
  }
}

bool DelimiterStack::isEmpty()
{
  bool status;

  if (top == nullptr)
    status = true;
  else
    status = false;

  return status;
}

char DelimiterStack::flipDelim(char delim)
{
  switch (delim)
  {
  case '{':
    delim = '}';
    break;
  case '}':
    delim = '{';
    break;
  case '(':
    delim = ')';
    break;
  case ')':
    delim = '(';
    break;
  case '[':
    delim = ']';
    break;
  case ']':
    delim = '[';
    break;
  }

  return delim;
}

DelimiterStack::Node* DelimiterStack::createNode(int line, int delimNum, char delimiter)
{
  Node* newNode = new Node;
  newNode->character = delimiter;
  newNode->charNum = delimNum;
  newNode->lineNum = line;

  return newNode;
}