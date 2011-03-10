/** Project 3b QuickSortedVecotrDictionary.h
  * Jie Chen * Patrick Maguire
  *
  *
  * This file contains the interface for the 
  * QuickSortedVecotrDictionary class
  *
  * This class inherits from SortedVectorDictionary, 
  * uses the selection sort algorithm
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

