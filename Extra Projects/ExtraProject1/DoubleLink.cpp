#include "DoubleLink.h"


DoubleLink::DoubleLink()
{
  lastAccessed = nullptr;
  head = nullptr;
  size = 0;
}

DoubleLink::DoubleLink(const DoubleLink &list)
{
  // Copy the size and create the new head
  size = list.size;
  Node* ptr = list.head;
  //head = createNode(-1);
  lastAccessed = nullptr;

  // Copy the rest of the nodes
  for (int i = 0; i < list.size; i++)
  {
    Node* newNode = createNode(ptr->data);
    newNode->prev = lastAccessed;

    if (i == 0)
      head = newNode;

    if (lastAccessed != nullptr)
      lastAccessed->next = newNode;

    lastAccessed = newNode;
    ptr = ptr->next;
  }

}

DoubleLink::~DoubleLink()
{
  Node* nextNode;
  lastAccessed = head;
  while (lastAccessed != nullptr)
  {
    nextNode = lastAccessed->next;
    delete lastAccessed;
    lastAccessed = nextNode;
  }
  //delete head;
  lastAccessed = head = nullptr;
  size = 0;
}

void DoubleLink::insert(int value)
{
  // Create the new node
  Node* newNode = createNode(value);

  // If head is not equal to null
  if (head != nullptr)
  {
    while ((lastAccessed->data > value))
    {
      // Check if the start of the list was found
      if (lastAccessed->prev == nullptr)
      {
        newNode->next = lastAccessed;
        lastAccessed->prev = newNode;
        head = newNode;
        size++;

        return;
      }

      // Check if the spot to insert the node was found
      else if (lastAccessed->prev->data < value)
      {
        newNode->next = lastAccessed;
        newNode->prev = lastAccessed->prev;
        lastAccessed->prev->next = newNode;
        lastAccessed->prev = newNode;
        size++;

        return;
      }

      lastAccessed = lastAccessed->prev;
    }

    while ((lastAccessed->data <= value))
    {
      // Check if the end of the list was found
      if (lastAccessed->next == nullptr)
      {
        newNode->prev = lastAccessed;
        newNode->next = nullptr;
        lastAccessed->next = newNode;
        size++;

        return;
      }

      // Check if the spot to insert the node was found
      else if (lastAccessed->next->data > value)
      {
        lastAccessed = lastAccessed->next;
        newNode->next = lastAccessed;
        newNode->prev = lastAccessed->prev;
        lastAccessed->prev = newNode;
        newNode->prev->next = newNode;
        size++;

        return;
      }

      lastAccessed = lastAccessed->next;
    }

  }

  // If the first node
  else
  {
    head = newNode;
    lastAccessed = newNode;
    size++;
  }
}

DoubleLink::Node* DoubleLink::search(int value)
{
  // If a Node has not been created yet or lastAccessed is already that value
  if (lastAccessed == nullptr || lastAccessed->data == value)
    return lastAccessed;
  
  // If lastAccessed is greater than value
  else if (lastAccessed->data > value)
  {
    while (lastAccessed != nullptr)
    {
      if (lastAccessed->data == value)
        return lastAccessed;

      lastAccessed = lastAccessed->prev;
    }
  }

  // If lastAccessed is smaller than value
  else
  {
    while (lastAccessed != nullptr)
    {
      if (lastAccessed->data == value)
        return lastAccessed;

      lastAccessed = lastAccessed->next;
    }
  }

  return nullptr;
}

void DoubleLink::remove(int value)
{
  Node* toRemove = search(value);

  // If the item was found in the linked list
  if (toRemove != nullptr)
  {
    if (toRemove->next != nullptr)
      toRemove->next->prev = toRemove->prev;

    toRemove->prev->next = toRemove->next;
    lastAccessed = toRemove->prev;
    delete toRemove;
    toRemove = nullptr;
    size--;
  }
}

int &DoubleLink::operator[](const int &value)
{
  Node* ptr = head;

  if (value > size)
    return head->data;

  for (int i = -1; i < value; i++)
  {
    if (ptr->next != nullptr)
      ptr = ptr->next;
  }

  return ptr->data;
}

void DoubleLink::display()
{
  Node* ptr = head->next;
  for (int i = 0; i < size; i++)
  {
    cout << this->operator[](i) << " ";
  }

  cout << endl;
}

DoubleLink::Node* DoubleLink::createNode(int value)
{
  Node* output = new Node();
  output->next = output->prev = nullptr;
  output->data = value;

  return output;
}