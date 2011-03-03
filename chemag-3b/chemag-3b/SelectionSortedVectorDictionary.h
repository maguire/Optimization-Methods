/** Project 3b QuickSortedVecotrDictionary.h
  * Jie Chen * Patrick Maguire
  *
  *
  * This file contains the interface for the Dictionary class
  **/

#include <vector>
#include <string>
#include "SortedVectorDictionary.h"

using namespace std;

class SelectionSortedVectorDictionary : public SortedVectorDictionary
{
public:
    SelectionSortedVectorDictionary(string file = "dictionary");

private:
    virtual void sort();
};

