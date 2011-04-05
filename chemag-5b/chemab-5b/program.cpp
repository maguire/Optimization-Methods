// Patrick Maguire & Jie Chen
//  Project 5a
//  Entry point and maze class


#include <cstdlib>
#include <iostream>
#include <limits.h>
#include "d_except.h"
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <fstream>
#include "d_matrix.h"
#include "graph.h"

using namespace std;


vector<int> getNeighbors(int id, graph &g)
// get all neighbors of the node with given id in graph g
{
    vector<int> lst;
    for (int i = 0; i < g.numNodes(); i++)
    {
        if (g.isEdge(id, i))
        {
            lst.push_back(i);
        }
    }

    return lst;
}

stack<int> nonRecursiveBFS(int startId, int dstId, graph &g )
// implement a version of Breadth First Search that uses a stack data structure
// and does not use recursion
{
    queue<int> q;
    stack<int> path;
    map<int, int> edges;
    q.push(startId);
    bool found = false;

    while (!q.empty())
    {
	int top = q.front();
	q.pop();

	if (top == dstId)
	{
	    found = true;
	    path.push(dstId);
	    break;
	}

	g.visit(top);
	vector<int> lst = getNeighbors(top, g);
	for (int i = 0; i < lst.size(); i++)
	{
	    if (!g.isVisited(lst[i]))
	    {
		q.push(lst[i]);
		edges.insert( pair<int, int>(lst[i], top) );
	    }
	}
    }

    // start backtracking
    int current = dstId;
    while (found && current != startId)
    {
	current = edges.find(current)->second;
	path.push(current);
    }
    return path;
}

vector<stack<int> > nonRecursiveDFS(int startId, int dstId, graph &g )
// implement a version of Depth First Search that uses a stack data structure
// and does not use recursion
{
    vector< stack<int> > paths;
    stack<int> st;
    stack<edge> edges;
    st.push(startId);
    stack<int> path;

    while (!st.empty())
    {
        int top = st.top();
        //check if before we had gone into a sink and remove from path
        while (!edges.empty() && path.top() != edges.top().getSource())
        {
            path.pop();
        }

        path.push(top);
        if (!edges.empty())
        {
            edges.pop();
        }
        st.pop();
        g.visit(top);
        if (top == dstId)
        {   
            paths.push_back(path);
        }
        vector<int> lst = getNeighbors(top, g);
        for (int i = 0; i < lst.size(); i++)
        {
            if (!g.isVisited(lst[i]))
            {
                st.push(lst[i]);
                edges.push(g.getEdge(top, lst[i]));
            }
        }

    }
    return paths;
}


void recursiveDFS(int curId, int dstId, graph &g,
                  stack<int> &path, bool &done)
// depth first search that uses the mem stack to search the graph g
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
            {
                recursiveDFS(current, dstId, g, path, done);
            }
            if (done)
                // if we found our node then construct our path
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

    int numRows()
    {
        return rows;
    };
    int numCols()
    {
        return cols;
    };

    void print(int, int, int, int);
    bool isLegal(int i, int j);

    void setMap(int i, int j, int n);
    int getMap(int i, int j) const;
    int getReverseMapI(int n) const;
    int getReverseMapJ(int n) const;

    void mapMazeToGraph(graph &g);

    void printPath(stack<int> &st);
    void findPathRecursive(graph &g);
    void findPathNonRecursive(graph &g);
    bool findShortestPath1(graph &g);
    bool findShortestPath2(graph &g);

private:
    int rows; // number of rows in the maze
    int cols; // number of columns in the maze
    matrix<int> map;
    vector<int> nMapi;
    vector<int> nMapj;
    matrix<bool> value;
};

bool maze::findShortestPath1(graph &g)
{

    g.clearVisit();
    g.clearMark();
    int start = getMap(0, 0);
    int end = getMap(numRows() - 1, numCols() - 1);
    vector< stack<int> > rpaths = nonRecursiveDFS(start, end, g);
    
    stack<int> reverse_path;
    
    for(int i = 0; i < rpaths.size(); i++)
        if (rpaths[i].size() > reverse_path.size())
            reverse_path = rpaths[i];

    stack<int> path;

    while (!reverse_path.empty())
    {
        int top = reverse_path.top();
        reverse_path.pop();
        if (g.isVisited(top))
        {
            path.push(top);
        }
    }

    printPath(path);

}
    
bool maze::findShortestPath2(graph &g)
{

    g.clearVisit();
    g.clearMark();
    int start = getMap(0, 0);
    int end = getMap(numRows() - 1, numCols() - 1);
    stack<int> path = nonRecursiveBFS(start, end, g);
    printPath(path);
}
void maze::findPathNonRecursive(graph &g)
// method for finding a path in the maze given a graph g representing the maze
// uses a stack based DFS
{
    g.clearVisit();
    g.clearMark();
    int start = getMap(0, 0);
    int end = getMap(numRows() - 1, numCols() - 1);
    vector< stack<int> > rpaths = nonRecursiveDFS(start, end, g);   
    stack<int> reverse_path;
    
    for(int i = 0; i < rpaths.size(); i++)
        if (rpaths[i].size() > reverse_path.size())
            reverse_path = rpaths[i];

    stack<int> path;

    while (!reverse_path.empty())
    {
        int top = reverse_path.top();
        reverse_path.pop();
        if (g.isVisited(top))
        {
            path.push(top);
        }
    }

    printPath(path);
}
void maze::findPathRecursive(graph &g)
// method for finding a path in the maze given a graph g representing the maze
// uses recursion based DFS
{
    g.clearVisit();
    g.clearMark();
    stack<int> path;
    int start = getMap(0, 0);
    int end = getMap(numRows() - 1, numCols() - 1);
    bool done = false;
    recursiveDFS(start, end, g, path, done);

    printPath(path);
}

void maze::setMap(int i, int j, int n)
// Set mapping from maze cell (i,j) to graph node n.
{
    map[i][j] = n;
    nMapi[n] = i;
    nMapj[n] = j;
}

int maze ::getMap(int i, int j) const
// Return mapping of maze cell (i,j) in the graph.
{
    return map[i][j];
}

int maze ::getReverseMapI(int n) const
// Return reverse mapping of node n to it's maze i value.
{
    return nMapi[n];
}

int maze ::getReverseMapJ(int n) const
// Return reverse mapping of node n to it's maze j value.
{
    return nMapj[n];
}

maze::maze(ifstream &fin)
// Initializes a maze by reading values from fin.  Assumes that the
// number of rows and columns indicated in the file are correct.
{
    fin >> rows;
    fin >> cols;

    char x;

    value.resize(rows, cols);
    for (int i = 0; i <= rows - 1; i++)
        for (int j = 0; j <= cols - 1; j++)
        {
            fin >> x;
            if (x == 'O')
            {
                value[i][j] = true;
            }
            else
            {
                value[i][j] = false;
            }
        }

    map.resize(rows, cols);
    nMapi.resize(rows * cols);
    nMapj.resize(rows * cols);
}

void maze::print(int goalI, int goalJ, int currI, int currJ)
// Print out a maze, with the goal and current cells marked on the
// board.
{
    cout << endl;

    if (goalI < 0 || goalI > rows || goalJ < 0 || goalJ > cols)
    {
        throw rangeError("Bad value in maze::print");
    }

    if (currI < 0 || currI > rows || currJ < 0 || currJ > cols)
    {
        throw rangeError("Bad value in maze::print");
    }

    for (int i = 0; i <= rows - 1; i++)
    {
        for (int j = 0; j <= cols - 1; j++)
        {
            if (i == goalI && j == goalJ)
            {
                cout << "*";
            }
            else if (i == currI && j == currJ)
            {
                cout << "+";
            }
            else if (value[i][j])
            {
                cout << " ";
            }
            else
            {
                cout << "X";
            }
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
    {
        throw rangeError("Bad value in maze::isLegal");
    }

    return value[i][j];
}

void maze::mapMazeToGraph(graph &g)
// Create a graph g that represents the legal moves in the maze m.
{
    for (int i = 0; i < value.rows(); i++)
    {
        for (int j = 0; j < value.cols(); j++)
        {
            if (isLegal(i, j))
            {
                int n = g.addNode();
                setMap(i, j, n);
                // only check above and to the left
                // since nodes down and to the right
                // have not been created
                if (i != 0 && isLegal(i - 1, j))
                {
                    g.addEdge(getMap(i - 1, j), n);
                }
                if (j != 0 && isLegal(i, j - 1))
                {
                    g.addEdge(getMap(i, j - 1), n);
                }
            }
        }
    }
}

void maze::printPath(stack<int> &st)
{
    if (st.empty())
    {
        cout << "no path found" << endl;
    }
    else
    {
        cout << "-----------------------------" << endl;
	
        int top;
        int ip, jp, prev = 0;
        int i;
        int j;
	int count = 0;

        while (!st.empty())
        {
	    count++;
            top = st.top();
            ip = getReverseMapI(prev);
            jp = getReverseMapJ(prev);
            i = getReverseMapI(top);
            j = getReverseMapJ(top);
            if (ip < i)
            {
                cout << "Go Down" << endl;
            }
            else if (ip > i)
            {
                cout << "Go Up" << endl;
            }
            else if (jp < j)
            {
                cout << "Go Right" << endl;
            }
            else if (jp > j)
            {
                cout << "Go Left" << endl;
            }

            print(numRows() - 1, numCols() - 1, i, j);
            st.pop();
            prev = top;
        }
	cout << "path length: " << count << endl;
    }
}

int main()
{
    ifstream fin;

    // Read the maze from the file.
    string fileName = "maze2.txt";

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
	    //m.print(m.numRows() - 1, m.numCols() - 1, 0, 0);
	    cout << g;
            m.findShortestPath1(g);
            m.findShortestPath2(g);
        }
    }
    catch (indexRangeError &ex)
    {
        cout << ex.what() << endl;
        exit(1);
    }
    catch (rangeError &ex)
    {
        cout << ex.what() << endl;
        exit(1);
    }
}
