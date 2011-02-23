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
#include "Dictionary.h"

using namespace std;

void checkSurrounding(int rowIndex, int colIndex,
                      const matrix<string> &mx,
                      const Dictionary &dict,
                      int deltaX, int deltaY, int minWordLength = 5)
// search for words in the direction given by delta x and y
// starting from the location rowIndex and colIndex
// for seach string longer than 5 check with the dictionary
// print the string if it is a word according to the dictionary
{
    if (deltaX == 0 && deltaY == 0)
    {
        // if there is no slope, we will go nowhere
        return;
    }
    int x = rowIndex;
    int y = colIndex;
    string currentWord = mx[x][y];
    while (currentWord.length() <= mx.rows())
    {
        if (currentWord.length() >= minWordLength)
        {
            if (dict.lookup(currentWord))
            {
                cout << currentWord << endl;
            }
        }
        if (deltaX + x >= mx.rows())
        {
            x = 0;
        }
        else if (deltaX + x < 0)
        {
            x = mx.rows() - 1;
        }
        else
        {
            x += deltaX;
        }

        if (y + deltaY >= mx.cols())
        {
            y = 0;
        }
        else if (y + deltaY < 0)
        {
            y = mx.cols() - 1;
        }
        else
        {
            y += deltaY;
        }

        currentWord = currentWord + mx[x][y];
    }
}

void findMatches(const Dictionary &dict, const Grid &g)
// search the grid for all strings and print the ones that are words
// according to the given dictionary
{
    matrix<string> mx = g.getMatrix();
    for (int i = 0; i < mx.rows(); i++)
    {
        for (int j = 0; j < mx.cols(); j++)
        {

            checkSurrounding(i, j, mx, dict, -1, -1);
            checkSurrounding(i, j, mx, dict, -1, 0);
            checkSurrounding(i, j, mx, dict, -1, 1);
            checkSurrounding(i, j, mx, dict, 0, -1);
            checkSurrounding(i, j, mx, dict, 0, 1);
            checkSurrounding(i, j, mx, dict, 1, -1);
            checkSurrounding(i, j, mx, dict, 1, 0);
            checkSurrounding(i, j, mx, dict, 1, 1);
        }
    }
}

void testSearch()
// test function that reads the grid file from the keyboard
// and runs search on the grid with a dictionary
{
    string gridFileName;
    cout << "Specify a WordSearch Grid : ";
    cin >> gridFileName;
    Grid g(gridFileName);
    findMatches(Dictionary(), g);
}


int main()
// the main function
{
    testSearch();
}
