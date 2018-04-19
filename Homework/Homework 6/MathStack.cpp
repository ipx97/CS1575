#include "MathStack.h"


void MathStack::add()
{
  int num, sum;

  // Pop the first two values off the stack. 
  pop(sum);
  pop(num);

  // Add the two values, store in sum. 
  sum += num;

  // Push sum back onto the stack 
  push(sum);
}

void MathStack::sub()
{
  int num, diff;

  // Pop the first two values off the stack. 
  pop(diff);
  pop(num);

  // Subtract num from diff. 
  diff -= num;

  // Push diff back onto the stack. 
  push(diff);
}

void MathStack::mult()
{
  int num1, num2;

  // Pop the two numbers
  pop(num1);
  pop(num2);

  // Push the product
  push(num1 * num2);
}

void MathStack::div()
{
  int num1, num2;

  // Pop the two numbers
  pop(num1);
  pop(num2);

  // Push the quotient
  push(num2 / num1);
}

void MathStack::addAll()
{
  int sum = 0, temp;

  while (!isEmpty())
  {
    pop(temp);
    sum += temp;
  }

  push(sum);
}

void MathStack::multAll()
{
  int product = 0, temp;

  while (!isEmpty())
  {
    pop(temp);
    product *= temp;
  }

  push(product);
}
