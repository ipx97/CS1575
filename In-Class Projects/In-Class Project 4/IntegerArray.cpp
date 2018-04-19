#include "IntegerArray.h"

bool IntegerArray::isValid(int index)
{
  if (size <= index + 1)
  {
    return false;
  }
  else
    return true;
}

IntegerArray::IntegerArray(int size)
{
  int* ptr = new int[size];

  for (int i = 0; i < size; i++)
  {
    ptr[i] = 0;
  }
}

IntegerArray::~IntegerArray()
{
  delete[]list;
  list = nullptr;
}

void IntegerArray::setElement(int index, int value)
{
  if (isValid(index))
  {
    list[index] = value;
  }

  return;
}

int IntegerArray::getElement(int index)
{
  if (isValid(index))
  {
    return list[index];
  }
  else
  {
    return NULL;
  }
}
