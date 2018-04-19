/******************************************************************************
* Course       : CS 2250 E01 (Fall 2015)
* Assignment   : Project 2
* Summary      : Converts an English sentence to pig latin
* Author       : Ian Piskulic
* Last Modified: October 2, 2015
******************************************************************************/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct Word
{
  string english;
  string piglatin;
};

/******************************************************************************
* Name    : splitSentence
* Purpose : To split a sentence up by words
* Inputs  : Takes an english sentence and the array size
* Outputs : Returns a pointer to the array of words
******************************************************************************/
Word* splitSentence(const string words, int& size);
/******************************************************************************
* Name    : convertToPigLatin
* Purpose : Converts each english field to piglatin
* Inputs  : An array of words and the size of the array
* Outputs : None.
******************************************************************************/
void convertToPigLatin(Word wordArr[], int size);
/******************************************************************************
* Name    : displayPigLatin
* Purpose : Displays the pig latin parts of the array
* Inputs  : An array of words and the size of the array
* Outputs : None.
******************************************************************************/
void displayPigLatin(const Word wordArr[], int size);
/******************************************************************************
* Name    : checkForVowel
* Purpose : Checks if the character is a vowel or not
* Inputs  : A character
* Outputs : A bool determining if the letter was vowel
******************************************************************************/
bool checkForVowel(char letter);

/******************************************************************************
* Name    : main
* Purpose : To test out the other functions created.
* Inputs  : None.
* Outputs : Returns 0 if ran successfully.
******************************************************************************/
int main()
{
  string englishSentence;
  int size;

  // Gets the English sentence from the user
  cout << "Hello! Please enter a sentence in English: ";
  getline(cin, englishSentence);

  // Splits up English sentence into words
  Word* words = splitSentence(englishSentence, size);

  // Generates the pig latin fields
  convertToPigLatin(words, size);

  // Outputs the new pig latin sentence
  displayPigLatin(words, size);

  // Deallocates memory
  delete[]words;
  words = NULL;

  return 0;
}

Word* splitSentence(const string words, int& size)
{
  // Counts the number of spaces to find the number of words
  string wordsCopy = words;
  int numWords = 0;


  for (int i = wordsCopy.size() - 1; i >= 0; i--)
  {
    wordsCopy[i] = tolower(wordsCopy[i]);

    // Checks for beginning or ending spaces
    if (isspace(wordsCopy[i]) && ((i == wordsCopy.size() - 1) || (i == 0))) 
    {
      wordsCopy = wordsCopy.erase(i, 1);
    }

    // Checks for two spaces in a row
    else if (isspace(wordsCopy[i]) && ((isspace(wordsCopy[i-1])) || (isspace(wordsCopy[i+1])))) 
    {
      wordsCopy = wordsCopy.erase(i, 1);
    }

    // Checks for punctuation or number
    else if ((!isalpha(wordsCopy[i])) && (!isspace(wordsCopy[i])))
    {
      wordsCopy = wordsCopy.erase(i, 1);
    }

    // Counts words
    else if (isalpha(wordsCopy[i]))
    {
      numWords++;

      do
      {
        i--;
      } while (isalpha(wordsCopy[i]) && i > 0);

      i++;
    }

  }
  
  // Creates the new array of Words
  size = numWords;
  Word* temp = new Word[size];

  for (int i = 0; i < size; i++)
  {
    temp[i].english = wordsCopy.substr(0, wordsCopy.find_first_of(' ')); // Grab the first word
    wordsCopy = wordsCopy.substr(wordsCopy.find_first_of(' ') + 1); // Strip the first word from the string
  }

  return temp;//return the array of strings
}

void convertToPigLatin(Word wordArr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    // If the first letter is a vowel
    if (checkForVowel(wordArr[i].english[0]))
    {
      wordArr[i].piglatin = (wordArr[i].english + "way");
    }

    // If the first letter is a consonant
    else
    {
      for (int j = 1; j < wordArr[i].english.length(); j++)
      {
        wordArr[i].piglatin += wordArr[i].english[j];
      }

      wordArr[i].piglatin += wordArr[i].english[0];
      wordArr[i].piglatin += "ay";
    }

  }

  return;
}

void displayPigLatin(const Word wordArr[], int size)
{
  cout << endl;
  for (int i = 0; i < size; i++)
  {
    cout << wordArr[i].piglatin + ' ';
  }

  cout << endl;

  return;
}

bool checkForVowel(char letter)
{
  bool output = false;

  switch (letter)
  {
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
    output = true;
    break;
  default:
    output = false;
  }

  return output;
}