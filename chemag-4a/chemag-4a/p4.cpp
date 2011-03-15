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

class board
// Stores the entire Sudoku board
{
public:
    board(int);
    void clear();
    void initialize(ifstream &fin);
    void print();
    void printConflicts();
    bool isBlank(int, int);
    ValueType getCell(int, int);
    void setCell(int i, int j, int val);
    bool hasConflict(int i, int j, int val);
      
private:
    void updateConflicts(int i, int j, int val, bool con);

    // The following matrices go from 1 to BoardSize in each
    // dimension.  I.e. they are each (BoardSize+1) X (BoardSize+1)

    matrix<ValueType> value;
    matrix<bool> rowConflict;
    matrix<bool> colConflict;
    matrix<bool> squareConflict;
};

board::board(int sqSize)
    : value(BoardSize+1,BoardSize+1), rowConflict(BoardSize+1,BoardSize+1),
      colConflict(BoardSize+1,BoardSize+1), 
      squareConflict(BoardSize+1,BoardSize+1)
// Board constructor
{
}

void board::clear()
{
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
{
    // maybe there should be a check to make sure the 
    // cell is empty?

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
{
    if (hasConflict(i, j, val))
	exit(0);// maybe we want to throw exception instead?

    value[i][j] = val;
    updateConflicts(i, j, val, true);
}

bool board::isBlank(int i, int j)
// Returns true if cell i,j is blank, and false otherwise.
{
    if (i < 1 || i > BoardSize || j < 1 || j > BoardSize)
	throw rangeError("bad value in setCell");
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

	while (fin && fin.peek() != 'Z')
	{
	    b1.initialize(fin);
	    b1.print();
	    b1.printConflicts();
	}
    }
    catch  (indexRangeError &ex)
    {
	cout << ex.what() << endl;
	exit(1);
    }
}

