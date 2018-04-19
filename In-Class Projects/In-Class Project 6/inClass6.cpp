#include <iostream>
#include <string>
using namespace std;

int raiseToPower(int num, int pow);
bool isPalindrome(string s);

int main()
{
  cout << raiseToPower(5, 2);
  bool out = isPalindrome("kayak");

  return 0;
}

int raiseToPower(int num, int pow)
{
  if (pow == 0)
    return 1;
  else
    return num * raiseToPower(num, pow - 1);
}

bool isPalindrome(string s)
{
    if (s.length() == 1)
      return 1;
    else if (s.length() == 2)
      return (s[0] == s[1]);
    else if (s[0] != s[s.length() - 1])
      return false;
    else
      return isPalindrome(s.substr(1, s.length() - 2));
}