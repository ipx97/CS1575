#include <fstream>
#include <string>
using namespace std;

char encrypt(char letter, char key);

int main()
{
  const char KEY = 243;
  fstream input;
  fstream output;
  char c;

  // Open each of the files
  input.open("unencrypted.txt", fstream::in);
  output.open("encrypted.txt", fstream::out);

  // Read and encrypt characters until end of file
  while (!input.eof())
  {
    input >> c;
    output << (int) encrypt(c, KEY);
  }
  
  return 0;
}

char encrypt(char letter, char key)
{
  return letter ^ key;
}