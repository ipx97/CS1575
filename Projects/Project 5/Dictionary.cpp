#include "Dictionary.h"
#include <iostream>
#include <vector>
#include <cctype>


Dictionary::Trie Dictionary::createTrie()
{
  Trie t = new TrieNode();

  // Set all pointers to nullptr
  for (int i = 0; i < ALPHABET_SIZE; i++)
    t->next[i] = nullptr;

  return t;
}

bool Dictionary::insertTrie(string word, string definition)
{
  Trie currentNode = root;
  string currentLetters = "";
  bool successStatus = false;

  // If a word is given, perform the insert
  if (word.length() > 0)
  {
    for (int i = 0; i < word.length(); i++)
    {
      word[i] = tolower(word[i]);
      currentLetters += word[i];
      int alphaPos = word[i] - 'a';

      // If no node exists, create one
      if (currentNode->next[alphaPos] == nullptr)
      {
        currentNode->next[alphaPos] = createTrie();
        currentNode->next[alphaPos]->word = currentLetters;
      }

      currentNode = currentNode->next[alphaPos];
    }

    // Once the final node is found/created, write the definition
    if (currentNode->definition == "")
    {
      currentNode->definition = definition;
      successStatus = true;
    }
  }

  return successStatus;
}

bool Dictionary::loadDictionary(string fileName)
{
  string line;
  ifstream file(fileName);
  bool successStatus = true;

  // If the file does not exist or isnt readable, return false
  if (!file.good())
    return false;

  // Read lines until end of file
  while (!file.eof())
  {
    getline(file, line);
    for (int i = 0; i < line.length(); i++)
    {
      if (line.at(i) == ':')
      {
        string word = line.substr(0, i);
        string definition = line.substr(i + 2);
        if (!insertTrie(word, definition))
          successStatus = false;

        break;
      }
    }
  }

  file.close();

  return successStatus;
}

string Dictionary::lookup(string word)
{
  Trie currentNode = root;
  string currentLetters = "";

  // If a word is given, look it up
  if (word.length() <= 0)
    return "";

  for (int i = 0; i < word.length(); i++)
  {
    word[i] = tolower(word[i]);
    currentLetters += word[i];
    int alphaPos = word[i] - 'a';

    // If no node exists, return null
    if (currentNode->next[alphaPos] == nullptr)
    {
      cout << "ERROR: " << word << " is not in the dictionary." << endl;
      return "";
    }

    currentNode = currentNode->next[alphaPos];
  }

  return currentNode->definition;
}

void Dictionary::deleteTrie()
{
  deleteNextNode(root);
}

void Dictionary::deleteNextNode(Trie t)
{
  Trie temp;
  for (int i = 0; i < ALPHABET_SIZE; i++)
  {
    if (t->next[i] != nullptr)
      deleteNextNode(t->next[i]);
  }
  delete t;
}

void Dictionary::displayTrie()
{
  displayNextNode(root);
}

void Dictionary::displayNextNode(Trie t)
{
  // Check for a pointer that isn't nullptr
  for (int i = 0; i < ALPHABET_SIZE; i++)
  {
    if (t->next[i] != nullptr)
    {
      if (t->next[i]->definition != "")
        cout << t->next[i]->word << ": " << t->next[i]->definition << endl;
      else if (t->next[i]->word != "")
        cout << t->next[i]->word << ':' << endl;

      displayNextNode(t->next[i]);
    }
  }
}

bool Dictionary::writeTrie(string fileName)
{
  fstream out;
  out.open(fileName, ios::out);
  writeNextWord(root, out);
  out.close();
  return true;
}

void Dictionary::writeNextWord(Trie t, fstream &file)
{
  // Check for a pointer that isn't nullptr
  for (int i = 0; i < ALPHABET_SIZE; i++)
  {
    if (t->next[i] != nullptr)
    {
      if (t->next[i]->definition != "")
        file << t->next[i]->word << ": " << t->next[i]->definition << endl;
      else if (t->next[i]->word != "")
        file << t->next[i]->word << ':' << endl;

      writeNextWord(t->next[i], file);
    }
  }
}

Dictionary::Dictionary()
{
  root = createTrie();
}

Dictionary::~Dictionary()
{
  deleteTrie();
  root = nullptr;
}
