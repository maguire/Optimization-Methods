/** Project 3b SelectionSortedVectorDictionary.h
  * Jie Chen * Patrick Maguire
  *
  *
  * This file contains the implementation for the 
  * SelectionSortedVectorDictionary class
  *   - defines selectionSort
  *   - defines sort
  *   - defines the public constructor
  *
  **/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "SelectionSortedVectorDictionary.h"

using namespace std;

SelectionSortedVectorDictionary::SelectionSortedVectorDictionary(string file) 
    : SortedVectorDictionary(file)
// constructor for the class, use constructor of its super class
// SortedVectorDictionary
{
    sort();
}

void selectionSort(vector<string> &unsorted)
// perform selection sort on the string vector
{
    for(int i = 0 ; i < unsorted.size() - 1; i++)
    {
        int nextSmallestIndex = i;
        for(int j = i + 1; j < unsorted.size(); j++)
        {   
            if ( unsorted[j] < unsorted[nextSmallestIndex]) 
            {
                nextSmallestIndex = j;
            }
        }
        swap ( unsorted[i], unsorted[nextSmallestIndex]);
    }
}

void SelectionSortedVectorDictionary::sort()
// sort the dictionary
{
    selectionSort(wordLst); 
}
