/** Patrick Maguire & Jie Chen 
 *  Project 4a
 *  Entry point and board class for sudoku
 */


// Declarations and functions for project #4

#include <iostream>
#include <limits.h>
#include "d_matrix.h"
#include "d_except.h"
#include <list>
#include <fstream>
#include <cstdlib>

using namespace std;

typedef int ValueType; // The type of the value in a cell
const int Blank = -1;  // Indicates that a cell is blank
 
const int SquareSize = 3;  //  The number of cells in a small square
                           //  (usually 3).  The board has
                           //  SquareSize^2 rows and SquareSize^2
                           //  columns.

const int BoardSize = SquareSize * SquareSize;

const int MinValue = 1;
const int MaxValue = 9;

int numSolutions = 0;

int CALL_COUNT = 0;
bool DONE = false;
long TOTAL_CALLS = 0;

class board
// Stores the entire Sudoku board
{
public:
    board(int);
    void clearCell(int i, int j);
    void clear();
    void initialize(ifstream &fin);
    void print();
    void printConflicts();
    bool isBlank(int, int);
    ValueType getCell(int, int);
    void setCell(int i, int j, int val);
    bool hasConflict(int i, int j, int val);
    bool isSolved();
    void solve(int i, int j);
      
private:
    void updateConflicts(int i, int j, int val, bool con);
    void next(int &row, int &col, int max);

    // The following matrices go from 1 to BoardSize in each
    // dimension.  I.e. they are each (BoardSize+1) X (BoardSize+1)

    matrix<ValueType> value;
    matrix<bool> rowConflict;
    matrix<bool> colConflict;
    matrix<bool> squareConflict;
};

void board::next(int &row, int &col, int max)
// helper for solve, should not be called outside of 
// solve
{
    if (col < max - 1)
	solve(row, col+1);
    else
	solve(row+1, 1);
}

void board::solve(int i = 1, int j = 1)
// solve the board and return the number of recursive calls made
{
    CALL_COUNT++;
    if (i > BoardSize)
    {
	DONE = true;
	return;
    }

    if (value[i][j] != 0)
    {
	next(i, j, value.rows());
	if (DONE) return;
    }
    else
    {
	for (int val = MinValue; val <= MaxValue; val++)
	{
	    if (!hasConflict(i, j, val))
	    {		
		setCell(i, j, val);
		updateConflicts(i, j, val, true);
		next(i, j, value.rows());
		if (DONE) return;
		clearCell(i, j);
	    }	
	}
    }
}

board::board(int sqSize)
    : value(BoardSize+1,BoardSize+1), rowConflict(BoardSize+1,BoardSize+1),
      colConflict(BoardSize+1,BoardSize+1), 
      squareConflict(BoardSize+1,BoardSize+1)
// Board constructor
{
}

void board::clearCell(int i, int j)
// remove all possible conflicts and set the cell value to 0
{
    updateConflicts(i, j, value[i][j], false);
    value[i][j] = 0;
}

void board::clear()
// clear the entire board
{
    for (int i = 1; i < value.rows(); i++)
    {
        for (int j = 1; j < value.cols(); j++)
        {
	    value[i][j] = 0;
	    for (int x = MinValue; x <= MaxValue; x++)
	    {
		updateConflicts(i, j, x, false);
	    }
        }
    }
}

bool board::isSolved()
// check if the board is solved(not necessarily correct)and print 
{
    for (int i = 1; i < value.rows(); i++)
    {
        for (int j = 1; j < value.cols(); j++)
        {
            if (value[i][j] == 0) return false;
        }
    }
    cout << endl;
    print();    
    return true;
}

void board::initialize(ifstream &fin)
// Read a Sudoku board from the input file.
{
    char ch;

    clear();
    for (int i = 1; i <= BoardSize; i++)
    {
        for (int j = 1; j <= BoardSize; j++)
        {
            fin >> ch;

            // If the read char is not Blank
            if (ch != '.')
            {
                
                if (hasConflict(i, j, ch-'0'))
		    throw rangeError("conflict on initialization");
		setCell(i,j,ch-'0');   // Convert char to int
		updateConflicts(i, j, ch-'0', true);
	    }
        }
    }
}

int squareNumber(int i, int j)
// Return the square number of cell i,j (counting from left to right,
// top to bottom.  Note that i and j each go from 1 to BoardSize
{
    // Note that (int) i/SquareSize and (int) j/SquareSize are the x-y
    // coordinates of the square that i,j is in.  

    return SquareSize * ((i-1)/SquareSize) + (j-1)/SquareSize + 1;
}


void board::updateConflicts(int i, int j, int val, bool con)
// update possible row, column, and square conflicts
{
    rowConflict[i][val] = con;
    colConflict[j][val] = con;
    squareConflict[squareNumber(i, j)][val] = con;
}

ostream &operator<<(ostream &ostr, vector<int> &v)
// Overloaded output operator for vector class.
{
    for (int i = 0; i < v.size(); i++)
	ostr << v[i] << " ";
    ostr << endl;
    return ostr;
}

bool board::hasConflict(int i, int j, int val)
// check if this board has a conflict at the given position and with val
{
    return rowConflict[i][val] || colConflict[j][val] ||
        squareConflict[squareNumber(i,j)][val];
}

ValueType board::getCell(int i, int j)
// Returns the value stored in a cell.  Throws an exception
// if bad values are passed.
{
    if (i >= 1 && i <= BoardSize && j >= 1 && j <= BoardSize)
	return value[i][j];
    else
	throw rangeError("bad value in getCell");
}

void board::setCell(int i, int j, int val)
// set the value of the cell, return true if value is set
// false otherwise
{
    value[i][j] = val;
}

bool board::isBlank(int i, int j)
// Returns true if cell i,j is blank, and false otherwise.
{
    if (i < 1 || i > BoardSize || j < 1 || j > BoardSize)
	throw rangeError("bad value in setCell");
    else
	return value[i][j] == Blank;
}

void board::print()
// Prints the current board.
{
    for (int i = 1; i <= BoardSize; i++)
    {
	if ((i-1) % SquareSize == 0)
	{
	    cout << " -";
	    for (int j = 1; j <= BoardSize; j++)
		cout << "---";
	    cout << "-";
	    cout << endl;
	}
	for (int j = 1; j <= BoardSize; j++)
	{
	    if ((j-1) % SquareSize == 0)
		cout << "|";
	    if (!isBlank(i,j))
		cout << " " << getCell(i,j) << " ";
	    else
		cout << "   ";
	}
	cout << "|";
	cout << endl;
    }

    cout << " -";
    for (int j = 1; j <= BoardSize; j++)
	cout << "---";
    cout << "-";
    cout << endl;
}

template <typename T>
static void printMx(const matrix<T> &mx)
// print the given matrix
{
    for (int i = 1; i < mx.rows(); i++)
    {
        for (int j = 1; j < mx.cols(); j++)
        {
            cout << mx[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void board::printConflicts()
// print all conflicts of this board
{
    cout << "row conflicts" << endl;
    printMx(rowConflict);
    cout << endl << "column conflicts" << endl;
    printMx(colConflict);
    cout << endl << "square conflicts" << endl;
    printMx(squareConflict);
}

int main()
{
    ifstream fin;
   
    // Read the sample grid from the file.
    string fileName = "sudoku.txt";

    fin.open(fileName.c_str());
    if (!fin)
    {
	cerr << "Cannot open " << fileName << endl;
	exit(1);
    }

    try
    {
	board b1(SquareSize);
	
	int num_round = 0;
	while (fin && fin.peek() != 'Z')
	{
	    num_round++;
	    DONE = false;
	    b1.initialize(fin);	    
	    cout << endl << "new board: " << endl;
	    b1.print();
	    b1.solve();
	    cout << "number of calls: " << CALL_COUNT << endl;
	    TOTAL_CALLS += CALL_COUNT;
	    CALL_COUNT = 0;
	    cout << "solved?: " << b1.isSolved() << endl;
	    
	}
	cout << "average number of calls: " << TOTAL_CALLS / num_round;
    }
    catch  (indexRangeError &ex)
    {
	    cout << ex.what() << endl;
	    exit(1);
    }
    catch (rangeError &x)
    {
	cout << x.what() << endl;
	exit(1);
    }
}

