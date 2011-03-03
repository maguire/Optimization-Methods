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

SortedVectorDictionary::SortedVectorDictionary(string file) 
    : VectorDictionary(file)
{}

int binarySearch(const vector<string> &lst, string word, int begin, int end) 
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
{
    return binarySearch(wordLst, word, 0, wordLst.size() - 1) != -1;
}

