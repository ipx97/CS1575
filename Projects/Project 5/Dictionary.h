#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <fstream>

using namespace std;

class Dictionary
{
  static const int ALPHABET_SIZE = 26;
  struct Node
  {
    string word;
    string definition;
    Node* next[ALPHABET_SIZE];
  };
  typedef Node TrieNode;
  typedef TrieNode* Trie;
  Trie root;
  /******************************************************************************
  * Name    : createTrie
  * Purpose : To construct a Trie object
  * Inputs  : None
  * Outputs : The new Trie
  ******************************************************************************/
  Trie createTrie();
  /******************************************************************************
  * Name    : writeNextWord
  * Purpose : To write the next word in the Trie
  * Inputs  : A Trie and the file stream
  * Outputs : None
  ******************************************************************************/
  void writeNextWord(Trie t, fstream &file);
  /******************************************************************************
  * Name    : displayNextNode
  * Purpose : To display the next word in the Trie
  * Inputs  : A Trie object
  * Outputs : None
  ******************************************************************************/
  void displayNextNode(Trie t);
  /******************************************************************************
  * Name    : deleteNextNode
  * Purpose : To delete the next node in the Trie
  * Inputs  : A Trie oject
  * Outputs : None
  ******************************************************************************/
  void deleteNextNode(Trie t);
public:
  /******************************************************************************
  * Name    : Dictionary
  * Purpose : To construct a Dictionary object
  * Inputs  : None
  * Outputs : None
  ******************************************************************************/
  Dictionary();
  /******************************************************************************
  * Name    : ~Dictionary
  * Purpose : To deconstruct a Dictionary object
  * Inputs  : None
  * Outputs : None
  ******************************************************************************/
  ~Dictionary();
  /******************************************************************************
  * Name    : deleteTrie
  * Purpose : To delete the whole Trie
  * Inputs  : None
  * Outputs : None
  ******************************************************************************/
  void deleteTrie();
  /******************************************************************************
  * Name    : insertTrie
  * Purpose : To insert a new Trie in the Dictionary
  * Inputs  : None
  * Outputs : A bool saying if the insert was successful
  ******************************************************************************/
  bool insertTrie(string word, string definition);
  /******************************************************************************
  * Name    : loadDictionary
  * Purpose : To load the dictionary from a text file
  * Inputs  : The file name of the dictionary
  * Outputs : A bool saying if the load was successful
  ******************************************************************************/
  bool loadDictionary(string fileName);
  /******************************************************************************
  * Name    : lookup
  * Purpose : To see what the definition of a word is in the dictionary
  * Inputs  : A word to lookup
  * Outputs : The definition of that word if it exists
  ******************************************************************************/
  string lookup(string word);
  /******************************************************************************
  * Name    : displayTrie
  * Purpose : To display the entire Trie
  * Inputs  : None
  * Outputs : None
  ******************************************************************************/
  void displayTrie();
  /******************************************************************************
  * Name    : writeTrie
  * Purpose : To write the whole Trie to a text file
  * Inputs  : The file name of the output file
  * Outputs : A bool saying if the write was successful
  ******************************************************************************/
  bool writeTrie(string fileName);

};

#endif // Dictionary.h