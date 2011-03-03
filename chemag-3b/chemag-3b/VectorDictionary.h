/** Project 3b VecotrUnsortedDictionary.h
  * Jie Chen * Patrick Maguire
  *
  *
  * This file contains the interface for the Dictionary class
  **/

#include <vector>
#include <string>
#include "Dictionary.h"

using namespace std;

class VectorDictionary : public Dictionary
{
public:
    VectorDictionary(string file = "dictionary");
    virtual bool lookup(string word) const;
protected:
    vector<string> wordLst; 
private:
    void init(string filename);
};
