/** Project 3b QuickSortedVectorDictionary.h
  * Jie Chen * Patrick Maguire
  *
  *
  * This file contains the interface for the QuickSortedVectorDictionary
  * class
  **/

#include <vector>
#include <string>
#include "SortedVectorDictionary.h"

using namespace std;

class QuickSortedVectorDictionary : public SortedVectorDictionary
{
public:
    QuickSortedVectorDictionary(string file = "dictionary");

private:
    virtual void sort();
};

