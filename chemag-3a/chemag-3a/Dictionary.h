/** Project 3a Dictionary.h
  * Jie Chen * Patrick Maguire
  *
  *
  * This file contains the interface for the Dictionary class
  **/

#include <vector>
#include <string>

using namespace std;

class Dictionary
{
public:
    Dictionary();
    bool lookup(string word) const;

private:
    vector<string> wordLst;
};
