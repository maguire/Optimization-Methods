/** Project 3a program.cpp
  * Jie Chen * Patrick Maguire
  *
  * This file contains the entry point for the program
  *
  * Also defines the findMatch and testSearch functions along with 
  * a helper function
  **/

#include <iostream>
#include "Grid.h"
//#include "SelectionSortedVectorDictionary.h"
#include "QuickSortedVectorDictionary.h"

using namespace std;

void checkSurrounding(int rowIndex, int colIndex,
                      const Grid &grid,
                      const Dictionary &dict,
                      const int deltaX, const int deltaY, 
		      const int minWordLength = 5)
// search for words in the direction given by delta x and y
// starting from the location rowIndex and colIndex
// for seach string longer than minWordLength check with the dictionary
// print the string if it is a word according to the dictionary
{
    if (deltaX == 0 && deltaY == 0)
    {
        // if there is no slope, we will go nowhere
        return;
    }
    int x = rowIndex;
    int y = colIndex;
    string currentWord = grid[x][y];
    while (currentWord.length() <= grid.size())
    {
        if (currentWord.length() >= minWordLength)
        {
            if (dict.lookup(currentWord))
            {
                cout << currentWord << endl;
            }
        }
        // make sure the x,y values are within range and wrap around
        x = (x + deltaX + grid.size()) % grid.size();
        y = (y + deltaY + grid.size()) % grid.size();
        
        currentWord = currentWord + grid[x][y];

    } //end while loop
} //end  checkSurrounding

void findMatches(const Dictionary &dict, const Grid &g)
// search the grid for all strings and print the ones that are words
// according to the given dictionary
{
    for (int i = 0; i < g.size(); i++)
    {
        for (int j = 0; j < g.size(); j++)
        {
            // check Up Left Diagonal
            checkSurrounding(i, j, g, dict, -1, -1);
            // check Up 
            checkSurrounding(i, j, g, dict, -1, 0);
            // check Up Right Diagonal
            checkSurrounding(i, j, g, dict, -1, 1);
            // check Left
            checkSurrounding(i, j, g, dict, 0, -1);
            // check Right
            checkSurrounding(i, j, g, dict, 0, 1);
            // check Down Left Diagonal
            checkSurrounding(i, j, g, dict, 1, -1);
            // check Down 
            checkSurrounding(i, j, g, dict, 1, 0);
            // check Down Right Diagonal
            checkSurrounding(i, j, g, dict, 1, 1);
        } //end inner for
    }// end outer for
}// end findMatches

void testSearch()
// function that reads the grid file from the keyboard
// and runs search on the grid with a dictionary
{
    string gridFileName;
    cout << "Specify a WordSearch Grid : ";
    cin >> gridFileName;
    Grid g(gridFileName);
    findMatches(QuickSortedVectorDictionary(), g);
}


int main()
// the main function
{
//   QuickSortedVectorDictionary();
    testSearch();
}
