/** Project 3b VecotrUnsortedDictionary.h
  * Jie Chen * Patrick Maguire
  *
  *
  * This file contains the interface for the Dictionary class
  **/

#include <vector>
#include <string>
#include "VectorDictionary.h"

using namespace std;

class SortedVectorDictionary : public VectorDictionary
{
public:
    SortedVectorDictionary(string file = "dictionary");
    virtual bool lookup(string word) const;
protected:
    virtual void sort() = 0;
};
