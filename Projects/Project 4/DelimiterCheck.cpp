/******************************************************************************
* Course       : CS 2250 E01 (Fall 2015)
* Assignment   : Project 4
* Summary      : Uses a delimiter stack
* Author       : Ian Piskulic
* Last Modified: November 9, 2015
******************************************************************************/

#include "DelimiterStack.h"
#include <string>
#include <cctype>

/******************************************************************************
* Name    : main
* Purpose : To test out the other functions created.
* Inputs  : None.
* Outputs : Returns 0 if ran successfully.
******************************************************************************/
int main()
{
  DelimiterStack* stack = new DelimiterStack();
  string line;
  int lineCount = 0;
  char openDelim[] = { '{', '(', '[' };
  char closDelim[] = { '}', ')', ']' };

  cout << "Type in some lines with delimiters!\n";

  // Do until a line says DONE
  do
  {
    getline(cin, line);
    lineCount++;

    for (int i = 0; i < line.length(); i++)
    {
      // If an opening delimiter
      if (line[i] == openDelim[0] || line[i] == openDelim[1] || line[i] == openDelim[2])
      {
        // Checks if you can allocate memory
        try
        {
          stack->push(lineCount, i, line[i]);
        }
        catch (const char* e)
        {
          cout << e;

          // Deallocate memory
          stack->~DelimiterStack();
          stack = nullptr;

          return 0;
        }
      }

      // If a closing delimiter
      else if (line[i] == closDelim[0] || line[i] == closDelim[1] || line[i] == closDelim[2])
      {
        char openChar = NULL;
        int lineNum, charNum;
        stack->pop(openChar, lineNum, charNum);

        // Check if there is anything in the stack
        if (openChar == NULL)
        {
          cout << "ERROR: No left delimiter found for the right delimiter '" 
            << line[i] << "' on line " << lineCount << ", char " << i + 1 << endl;
        }

        // Check if the delimiter flipped equals the popped delimiter
        else if (openChar != stack->flipDelim(line[i]))
        {
          cout << "ERROR: Delimiter " << line[i] << " on line " << lineCount << " char " 
            << i + 1 << " does not match the delimiter " << openChar << " found on line " 
            << lineNum << ", char " << charNum + 1 << endl;
        }
      }
    }
  } while (line != "DONE");

  // Check if any unused delimiters are left
  while (!stack->isEmpty())
  {
    char openChar = NULL;
    int lineNum, charNum;
    stack->pop(openChar, lineNum, charNum);

    cout << "ERROR: Left delimiter " << openChar << " found on line " << lineNum
      << ", char " << charNum + 1 << " has no right delimiter." << endl;
  }

  // Deallocate memory
  stack->~DelimiterStack();
  stack = nullptr;

  return 0;
}

