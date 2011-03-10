/** Project 3b SortedVectorDictionary.h
  * Jie Chen * Patrick Maguire
  *
  * This file contains the implementations for the 
  * SortedVectorDictionary class
  *   - defines binary search
  *   - defines lookup 
  **/

#include <vector>
#include <string>
#include "SortedVectorDictionary.h"

using namespace std;

SortedVectorDictionary::SortedVectorDictionary(string file) 
    : VectorDictionary(file)
// constructor for the SortedBectorDictionary class
// calls the constructor of its super class VectorDictionary
{}

int binarySearch(const vector<string> &lst, string word, int begin, int end) 
// perform binary search on 'lst' looking for 'word'
{
    if (begin > end) return -1;
    
    int mid = (begin + end) / 2;
    
    if (lst[mid] == word)
    {
        return mid;
    }
    else if (word < lst[mid])
    {  
        return binarySearch(lst, word, begin, mid - 1);
    }
    else if (word > lst[mid])
    {
        return binarySearch(lst,word, mid + 1, end);
    } 
}

bool SortedVectorDictionary::lookup(string word) const
// look up function, calls binary search.  overrides the
// look up function in its super class VectorDictionary
{
    return binarySearch(wordLst, word, 0, wordLst.size() - 1) != -1;
}

