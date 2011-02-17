/** Project 3a Dictionary.h
  * Jie Chen * Patrick Maguire
  * 
  * 
  * This file contains the interface for the Dictionary class
  **/

#include <vector>
#include <string>

class Dictionary
{
public:
    Dictionary();
    bool lookup(string word);
  
private:
    vector<string> wordLst;
};
