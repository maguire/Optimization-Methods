// Project 5

#include <cstdlib>
#include <iostream>
#include <limits.h>
#include "d_except.h"
#include <list>
#include <fstream>
#include "d_matrix.h"
#include "graph.h"

using namespace std;

list<int> getNeighbors(int id, graph &g);
void findPathRecursive(int srcId, int dstId, graph &g);
void findPathNonRecursive(int srcId, int dstId, graph &g);

list<int> getNeighbors(int id, graph &g)
{

}

void findPathRecurisve(int curId, int dstId, graph &g)
{
    node n = g.getNode(curId);
    n.visit();
    n.mark();

    
}


class maze
{
   public:
      maze(ifstream &fin);

      int numRows(){return rows;};
      int numCols(){return cols;};

      void print(int,int,int,int);
      bool isLegal(int i, int j);

      void setMap(int i, int j, int n);
      int getMap(int i, int j) const;
      int getReverseMapI(int n) const;
      int getReverseMapJ(int n) const;

      void mapMazeToGraph(graph &g);

   private:
      int rows; // number of rows in the maze
      int cols; // number of columns in the maze
      matrix<int> map;
      matrix<bool> value;
};

void maze::setMap(int i, int j, int n)
// Set mapping from maze cell (i,j) to graph node n. 
{
    map[i][j] = n;
}

int maze ::getMap(int i, int j) const
// Return mapping of maze cell (i,j) in the graph.
{
    return map[i][j];
}

int maze ::getReverseMapI(int n) const
// Return reverse mapping of node n to it's maze i value.
{
    return n % rows;
}

int maze ::getReverseMapJ(int n) const
// Return reverse mapping of node n to it's maze j value.
{
    return n % cols;
}

maze::maze(ifstream &fin)
// Initializes a maze by reading values from fin.  Assumes that the
// number of rows and columns indicated in the file are correct.
{
   fin >> rows;
   fin >> cols;

   char x;

   value.resize(rows,cols);
   for (int i = 0; i <= rows-1; i++)
      for (int j = 0; j <= cols-1; j++)
      {
	 fin >> x;
	 if (x == 'O')
            value[i][j] = true;
	 else
	    value[i][j] = false;
      }

   map.resize(rows,cols);
}

void maze::print(int goalI, int goalJ, int currI, int currJ)
// Print out a maze, with the goal and current cells marked on the
// board.
{
   cout << endl;

   if (goalI < 0 || goalI > rows || goalJ < 0 || goalJ > cols)
      throw rangeError("Bad value in maze::print");

   if (currI < 0 || currI > rows || currJ < 0 || currJ > cols)
      throw rangeError("Bad value in maze::print");

   for (int i = 0; i <= rows-1; i++)
   {
      for (int j = 0; j <= cols-1; j++)
      {
	 if (i == goalI && j == goalJ)
	    cout << "*";
	 else
	    if (i == currI && j == currJ)
	       cout << "+";
	    else
	       if (value[i][j])
		  cout << " ";
	       else
		  cout << "X";	  
      }
      cout << endl;
   }
   cout << endl;
}

bool maze::isLegal(int i, int j)
// Return the value stored at the (i,j) entry in the maze, indicating
// whether it is legal to occupy cell (i,j).
{
   if (i < 0 || i > rows || j < 0 || j > cols)
      throw rangeError("Bad value in maze::isLegal");

   return value[i][j];
}

void maze::mapMazeToGraph(graph &g)
// Create a graph g that represents the legal moves in the maze m.
{
    for(int i = 0; i < value.rows(); i++)
    {
        for(int j = 0; j < value.cols(); j++)
        {
            if (isLegal(i, j))
            {
                int n = g.addNode();
                setMap(i,j,n);
		// only check above and to the left
		// since nodes down and to the right
		// have not been created
                if (i != 0 && isLega(i-1, j))
                {
                   g.addEdge(n, getMap(i-1,j)); 
                }
		if (j != 0 && isLegal(i, j-1))
                {
                   g.addEdge(n, getMap(i,j-1));
                }
            }
        }
    }
}

int main()
{
   char x;
   ifstream fin;
   
   // Read the maze from the file.
   string fileName = "maze1.txt";

   fin.open(fileName.c_str());
   if (!fin)
   {
      cerr << "Cannot open " << fileName << endl;
      exit(1);
   }

   try
   {
      graph g;
      while (fin && fin.peek() != 'Z')
      {
         maze m(fin);
         m.mapMazeToGraph(g);
         cout << g;
         m.print(m.numRows()-1, m.numCols()-1, 0, 0);
      }
   } 
   catch (indexRangeError &ex) 
   { 
      cout << ex.what() << endl; exit(1);
   }
   catch (rangeError &ex)
   {
      cout << ex.what() << endl; exit(1);
   }
}
