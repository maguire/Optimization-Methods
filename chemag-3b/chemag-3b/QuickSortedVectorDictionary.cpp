
/** Project 3b QuickSortedVectorDictionary.h
  * Jie Chen * Patrick Maguire
  *
  *
  * This file contains the implementation for the QuickSortedVectorDictionary 
  * class
  *   - defines partition, quickSort, and the constructor
  **/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "QuickSortedVectorDictionary.h"

using namespace std;

QuickSortedVectorDictionary::QuickSortedVectorDictionary(string file) 
    : SortedVectorDictionary(file)
// constructor for QuickSortedVectorDictionary, call the constructor
// of SortedVectorDictionary
{
    sort();
}

int partition(vector<string> &unsorted, int begin, int end, int pivotIndex)
// parition the vector around the pivot such that, all smaller values are 
// on left and larger values are on right of the pivot
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
// do quick sort on string vector
{
    if( end > begin )
    {
        int pivot = (begin + end) / 2;
        pivot = partition(unsorted, begin, end, pivot);
        quickSort(unsorted, begin, pivot - 1);
        quickSort(unsorted, pivot + 1, end); 
    }
}

void QuickSortedVectorDictionary::sort()
// sorts the dictionary by calling quicksort
{
    quickSort(wordLst, 0, wordLst.size()-1); 
    print();
}
