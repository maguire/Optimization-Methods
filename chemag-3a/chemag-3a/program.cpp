#include <iostream>
#include "Grid.h"
#include "Dictionary.h"

using namespace std;

void checkSurrounding(int rowIndex, int colIndex, const matrix<string> &mx, const Dictionary &dict, int minWordLength, int deltaX, int deltaY)

{
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

void checkUp(int rowIndex, int colIndex, const matrix<string> &mx, const Dictionary &dict, int minWordLength = 5)

{
    checkSurrounding(rowIndex, colIndex, mx, dict, minWordLength, 0, -1);
}
void checkDown(int rowIndex, int colIndex, const matrix<string> &mx, const Dictionary &dict, int minWordLength = 5)

{
    checkSurrounding(rowIndex, colIndex, mx, dict, minWordLength, 0, 1);
}
void checkRight(int rowIndex, int colIndex, const matrix<string> &mx, const Dictionary &dict, int minWordLength = 5)

{
    checkSurrounding(rowIndex, colIndex, mx, dict, minWordLength, 1, 0);
}
void checkLeft(int rowIndex, int colIndex, const matrix<string> &mx, const Dictionary &dict, int minWordLength = 5)

{
    checkSurrounding(rowIndex, colIndex, mx, dict, minWordLength, -1, 0);
}
void checkDownRightDiag(int rowIndex, int colIndex, const matrix<string> &mx, const Dictionary &dict, int minWordLength = 5)

{
    checkSurrounding(rowIndex, colIndex, mx, dict, minWordLength, 1, 1);
}
void checkDownLeftDiag(int rowIndex, int colIndex, const matrix<string> &mx, const Dictionary &dict, int minWordLength = 5)

{
    checkSurrounding(rowIndex, colIndex, mx, dict, minWordLength, -1, 1);
}
void checkUpRightDiag(int rowIndex, int colIndex, const matrix<string> &mx, const Dictionary &dict, int minWordLength = 5)

{
    checkSurrounding(rowIndex, colIndex, mx, dict, minWordLength, 1, -1);
}

void checkUpLeftDiag(int rowIndex, int colIndex, const matrix<string> &mx, const Dictionary &dict, int minWordLength = 5)

{
    checkSurrounding(rowIndex, colIndex, mx, dict, minWordLength, -1, -1);
}

void findMatches(const Dictionary &dict, const Grid &g)

{
    matrix<string> mx = g.getMatrix();
    for (int i = 0; i < mx.rows(); i++)
    {
        for (int j = 0; j < mx.cols(); j++)
        {
            checkUp(i, j, mx, dict );
            checkDown(i, j, mx, dict);
            checkLeft(i, j, mx, dict);
            checkRight(i, j, mx, dict);
            checkDownRightDiag(i, j, mx, dict);
            checkDownLeftDiag(i, j, mx, dict);
            checkUpRightDiag(i, j, mx, dict);
            checkUpLeftDiag(i, j, mx, dict);
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
