// Project 5

#include <cstdlib>
#include <iostream>
#include <limits.h>
#include "d_except.h"
#include <list>
#include <vector>
#include <stack>
#include <fstream>
#include "d_matrix.h"
#include "graph.h"

using namespace std;

vector<int> getNeighbors(int id, graph &g);
void recursiveDFS(int srcId, int dstId, graph &g, 
                  stack<int> &path, bool &done);

vector<int> getNeighbors(int id, graph &g)
{
    vector<int> lst;
    for (int i = 0; i < g.numEdges(); i++)
    {
	if (g.isEdge(id, i))
	    lst.push_back(i);
    }
    
    return lst;
}

vector<int> nonRecursiveDFS(int startId, int dstId, graph &g )
{
    vector<int> path;
    if( startId == dstId )
        path.push_back(startId);
    else
    {
        stack<int> nodes;
        g.mark(startId);
        g.visit(startId);
        nodes.push(startId);
        while(!nodes.empty())
        {  
             
            int curId = nodes.top();
            nodes.pop();
            path.push_back(curId);
            if (curId == dstId) return path;
            vector<int> lst = getNeighbors(curId, g);
            for(int i = 0; i < lst.size(); i++)
            {
                if(!g.isVisited(lst[i])) {
                    nodes.push(lst[i]);
                }
            }
        }
    }
    return vector<int>();

}


void recursiveDFS(int curId, int dstId, graph &g,
		        stack<int> &path, bool &done)
{
    if (curId == dstId)
    {
        done = true;
        path.push(curId);
    }
    else
    {
        g.mark(curId);
        g.visit(curId);
        
        vector<int> lst = getNeighbors(curId, g);
    
        while (!lst.empty())
        {
            int current =  lst.back();
            lst.pop_back();

            if (!g.isVisited(current)) 
                recursiveDFS(current, dstId, g, path, done);
            if (done) 
            {
                path.push(curId);
                break;
            }
        }
    }
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

      void findPathRecursive(graph &g);
      void findPathNonRecursive(graph &g);

   private:
      int rows; // number of rows in the maze
      int cols; // number of columns in the maze
      matrix<int> map;
      matrix<bool> value;
};

void maze::findPathNonRecursive(graph &g)
{
    g.clearVisit();
    g.clearMark();
    int start = getMap(0,0);
    int end = getMap(numRows()-1, numCols()-1);
    vector<int> path = nonRecursiveDFS(start, end, g);
    
    for( int i =0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;       
}
void maze::findPathRecursive(graph &g)
{
    g.clearVisit();
    g.clearMark();
    stack<int> path;
    int start = getMap(0,0);
    int end = getMap(numRows()-1, numCols()-1);
    bool done = false;
    recursiveDFS(start, end, g, path, done);

    while (!path.empty())
    {
        cout << path.top() << " ";
        path.pop();
    }
    cout << endl;       
}

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
                if (i != 0 && isLegal(i-1, j))
                {
                    g.addEdge(getMap(i-1,j), n);
                }
		        if (j != 0 && isLegal(i, j-1))
                {
                    g.addEdge(getMap(i,j-1), n);
                }
            }
        }
    }
}

int main()
{
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
      stack<int> st;
      while (fin && fin.peek() != 'Z')
      {
         maze m(fin);
         m.mapMazeToGraph(g);
         cout << g;
         m.findPathRecursive(g);
         m.findPathNonRecursive(g);
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
