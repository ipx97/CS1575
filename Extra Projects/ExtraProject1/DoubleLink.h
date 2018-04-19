#ifndef DOUBLELINK_H
#define DOUBLELINK_H

#include <iostream>
using namespace std;

class DoubleLink
{
private:
  struct Node
  {
    int data;
    Node* prev;
    Node* next;
  };
  Node* head;
  Node* lastAccessed;
  int size;
  /******************************************************************************
  * Name    : search
  * Purpose : To search the list for the node containing a certain value
  * Inputs  : The value to search for
  * Outputs : The pointer to the node of the value found
  ******************************************************************************/
  Node* search(int value);
  /******************************************************************************
  * Name    : createNode
  * Purpose : Creates a node with the value given
  * Inputs  : A value to be used as the data
  * Outputs : The node pointer for the new node
  ******************************************************************************/
  Node* createNode(int value);
public:
  /******************************************************************************
  * Name    : DoubleLink
  * Purpose : To construct a DoubleLink object
  * Inputs  : None
  * Outputs : None
  ******************************************************************************/
  DoubleLink();
  /******************************************************************************
  * Name    : DoubleLink
  * Purpose : To construct a DoubleLink object
  * Inputs  : Another DoubleLink object
  * Outputs : None
  ******************************************************************************/
  DoubleLink(const DoubleLink &list);
  /******************************************************************************
  * Name    : ~DoubleLink
  * Purpose : To deconstruct a DoubleLink object
  * Inputs  : None
  * Outputs : None
  ******************************************************************************/
  ~DoubleLink();
  /******************************************************************************
  * Name    : insert
  * Purpose : To insert a value into the list
  * Inputs  : An int value
  * Outputs : None
  ******************************************************************************/
  void insert(int value);
  /******************************************************************************
  * Name    : remove
  * Purpose : To remove a node from a list
  * Inputs  : The value to remove
  * Outputs : None
  ******************************************************************************/
  void remove(int value);
  /******************************************************************************
  * Name    : operator[]
  * Purpose : To overload the [] operator to make the list act like an array
  * Inputs  : The index of the node
  * Outputs : The node data value at that index
  ******************************************************************************/
  int &operator[] (const int &index);
  /******************************************************************************
  * Name    : display
  * Purpose : To display the contents of a list
  * Inputs  : None
  * Outputs : None
  ******************************************************************************/
  void display();
};

#endif // DoubleLink.h