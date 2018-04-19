/*
******************************************************************************
* Course       : CS 2250 E01 (Fall 2015)
* Assignment   : Homework 5
* Author       : Ian Piskulic
* Last Modified: October 17, 2015
******************************************************************************

Review Questions and Excercises (Chapter 14):

2. Numbers.showTotal();

5. This is not a good idea because it will allow the whole class to access the
members of the other class.

11. A default copy constructor is used to generate a copy of an object.

15. By putting in a dummy parameter, the compiler will know to use it in postfix and not prefix.

18. 
  Stuff blob = clump; <- copy constructor
  clump = blob; <- copy constructor
  blob.operator=(clump); <- overloaded =
  showValues(blob); // blob is passed by value. <- copy constructor

Review Questions and Excercises (Chapter 16):

5. When a throw statement executes and the exception is not caught, which results in all of the functions
from the throw point to the try block to terminate.

7. You can either put a try catch around the new function, or you can deallocate enough memory
before hand so that you won't ever have a problem allocating memory.

13. throw point

24.
    int searchArray(int val, int arr, int size)
    {
      int output = size + 1;
      try
      {
        for (int i = 0; i < size; i++)
        {
          if (arr[i] == val)
          {
            output = i;
            break;
          }
        }

        if (output == size + 1)
        {
          throw output;
        }

      }
      catch (int e)
      {
        cout << "Could not find value in array";
      }
    }

49. *Both ints need to be replaced with 'T'
    *There needs to be <T> in front of the function name

Review Questions and Excercises (Chapter 17):

1. *They can be resized
   *You can insert and delete elements
   *You can add elements to the front and back

3. The list head is a pointer that points the the first node in the list

15. the first node

26. F

33. *nodePtr is undefined pointer
    *nodePtr->next is not a boolean value

*/

// Programming Challenge #4 (Chapter 14)

// Written in NumDays.h and NumDays.cpp

// Programming Challenge #4 (Chapter 16)

template <class T>
T absoluteValue(T num)
{
  if (num < 0)
    num *= -1;

  return num;
}