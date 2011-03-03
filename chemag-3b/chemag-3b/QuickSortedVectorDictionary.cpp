
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
#include "QuickSortedVectorDictionary.h"

using namespace std;

QuickSortedVectorDictionary::QuickSortedVectorDictionary(string file) 
    : SortedVectorDictionary(file)
{
    sort();
}

int partition(vector<string> &unsorted, int begin, int end, int pivotIndex)
{
    swap(unsorted[pivotIndex], unsorted[end]);
    int start = begin;

    for (int i = begin; i < end; i++)
    {
        if (unsorted[i] <= unsorted[end])
        {
            swap ( unsorted[i], unsorted[start]);
            start++;
        }
    }
    swap (unsorted[start] , unsorted[end]);
    return start;
}


void quickSort(vector<string> &unsorted, int begin, int end)
{
    if( end > begin ){
        int pivot = (begin + end) / 2;
        pivot = partition(unsorted, begin, end, pivot);
        quickSort(unsorted, begin, pivot - 1);
        quickSort(unsorted, pivot + 1, end); 
    }
}
void QuickSortedVectorDictionary::sort()
{
    quickSort(wordLst, 0, wordLst.size()-1); 
    for (int i = 0; i < wordLst.size() ; i++)
        cout << wordLst[i] << endl ;
}
