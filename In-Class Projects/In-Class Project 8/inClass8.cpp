#include <stack>
#include <queue>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
  ifstream input("unencrypted.txt");
  ofstream reverse, upper;
  string word = "";
  stack<string> words;
  queue<string> otherWords;

  // Read in text to stack and queue
  while (input >> word)
  {
    words.push(word);
    otherWords.push(word);
  }

  input.close();

  // Output stack
  reverse.open("reverse.txt", fstream::out);
  while (!words.empty())
  {
    reverse << words.top();
    reverse << ' ';
    words.pop();
  }

  reverse.close();

  // Output queue
  upper.open("upper.txt", fstream::out);
  while (!otherWords.empty())
  {
    word = otherWords.front();
    otherWords.pop();

    for (int i = 0; i < word.length(); i++)
      word[i] = toupper(word[i]);

    upper << word;
    upper << ' ';
  }

  upper.close();

  return 0;
}