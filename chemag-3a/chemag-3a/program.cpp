#include <iostream>
#include "Grid.h"
#include "Dictionary.h"

using namespace std;

void checkSurrounding(int rowIndex, int colIndex, const matrix<string> &mx, const Dictionary &dict, int deltaX, int deltaY, int minWordLength = 5)

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

{
    matrix<string> mx = g.getMatrix();
    for (int i = 0; i < mx.rows(); i++)
    {
        for (int j = 0; j < mx.cols(); j++)
        {
            for(int x = -1; x < 2; x++)
            {
                for( int y = -1; y < 2; y++)
                {
                    checkSurrounding(i, j, mx, dict, x, y);
                }
            }
        }
    }

}

void testSearch()
{
    string gridFileName;
    cout << "Specify a WordSearch Grid : ";
    cin >> gridFileName;
    Grid g(gridFileName);
    findMatches(Dictionary(), g);
}

int main()
{
    testSearch();
}
