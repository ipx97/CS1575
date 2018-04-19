/******************************************************************************
* Course       : CS 2250 E01 (Fall 2015)
* Assignment   : Project 5
* Summary      : Creates a dictionary using a trie
* Author       : Ian Piskulic
* Last Modified: December 5, 2015
******************************************************************************/
#include "Dictionary.h"
#include <iostream>

/******************************************************************************
* Name    : main
* Purpose : To test out the other functions created.
* Inputs  : None.
* Outputs : Returns 0 if ran successfully.
******************************************************************************/
int main()
{
  Dictionary* d = new Dictionary();
  string inputFileName;
  string outputFileName;
  string wordToLookup;
  char decision;

  // Get the dictionary file name
  cout << "Hello! Please enter the name of the dictionary file: ";
  cin >> inputFileName;

  // Load the dictionary
  while (!d->loadDictionary(inputFileName))
  {
    cout << "\nERROR: Could not load dictionary from that file.\n";
    cout << "Please enter a new file name: ";
    cin >> inputFileName;
  }

  cout << endl << "Loading dictionary..." << endl;


  // Ask to lookup words
  do
  {
    do
    {
      cout << "\nWould you like to lookup a word (y/n)? ";
      cin >> decision;

      // Check if the decision is a possible decision
      if (decision != 'y' && decision != 'n')
        cout << "ERROR: Invalid decision!";

    } while (decision != 'y' && decision != 'n');

    // If they want to lookup a word, ask for the word
    if (decision == 'y')
    {
      cout << "Enter a word: ";
      cin >> wordToLookup;

      // If the defintion is not found, don't try to output it
      if (d->lookup(wordToLookup) != "")
        cout << "Definition: " << d->lookup(wordToLookup) << endl;
    }

  } while (decision != 'n');


  // Ask if they want to write the dictionary to a file
  do
  {
    cout << "\nWould you like to write the dictionary to a file (y/n)? ";
    cin >> decision;

    // Check if the decision is a possible decision
    if (decision != 'y' && decision != 'n')
      cout << "ERROR: Invalid decision!";

  } while (decision != 'y' && decision != 'n');

  // If yes, ask for the file name
  if (decision == 'y')
  {
    do
    {
      cout << "Please enter the name of the output file: ";
      cin >> outputFileName;
    } while (!d->writeTrie(outputFileName));

    cout << endl << "Writing dictionary..." << endl;
  }

  d->insertTrie("cat", "meow");

  // End the program
  cout << endl << "THE END." << endl;
  d->~Dictionary();
  d = nullptr;

  return 0;
}