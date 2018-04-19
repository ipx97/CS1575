#ifndef INTEGERARRAY_H
#define INTEGERARRAY_H

#include <iostream>
using namespace std;

class IntegerArray
{
private:
  int* list = new int[size];
  int size = 10;
  bool isValid(int index);
public:
  IntegerArray(int size);
  ~IntegerArray();
  void setElement(int index, int value);
  int getElement(int index);
};

#endif INTEGERARRAY_H