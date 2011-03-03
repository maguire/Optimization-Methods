
/** Project 3b QuickSortedVecotrDictionary.h
  * Jie Chen * Patrick Maguire
  *
  *
  * This file contains the interface for the Dictionary class
  **/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "SelectionSortedVectorDictionary.h"

using namespace std;

SelectionSortedVectorDictionary::SelectionSortedVectorDictionary(string file) 
    : SortedVectorDictionary(file)
{
    sort();
}

void selectionSort(vector<string> &unsorted)
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
{
    selectionSort(wordLst); 
    for (int i = 0; i < wordLst.size(); i++)
        cout << wordLst[i];
}
