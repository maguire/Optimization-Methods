// Project 6

#include <iostream>
#include <limits.h>
#include "d_except.h"
#include <list>
#include <fstream>
#include "d_matrix.h"
#include "graph.h"
#include <queue>
#include <stack>
#include <vector>
#include <stdlib.h>

using namespace std;

int const NONE = -1;  // Used to represent a node that does not exist

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
void exploreDFS(graph &g, bool &cyclic)
// implement a version of Depth First Search that uses a stack data structure
// and does not use recursion
{
    stack<int> st;
    st.push(0);

    while (!st.empty())
    {
        int top = st.top();

        st.pop();
        g.visit(top);
        vector<int> lst = getNeighbors(top, g);
         for (int i = 0; i < lst.size(); i++)
        {
            if (!g.isVisited(lst[i]))
            {
		// mark edges so that we don't fall for 
		// trivial cycles
		g.getEdge(top, lst[i]).mark();
		g.getEdge(lst[i], top).mark();
                st.push(lst[i]);
            }
            else if (!g.getEdge(top, lst[i]).isMarked())
            {
		// we only have a cycle if the second edge used to get to 
		// the node haven't already been used
                cyclic = true;
            }
        }

    }
}

bool isCyclic(graph &g)
// Returns true if the graph g contains a cycle.  Otherwise, returns false.
{
    bool cyclic = false;
    exploreDFS( g, cyclic);
    return cyclic;
}
bool isConnected(graph &g)
// Returns true if the graph g is connected.  Otherwise returns false.
{
    g.clearVisit();
    bool c = false;
    exploreDFS(g, c);
    for ( int i = 0; i < g.numNodes(); i++)
    {
        if(!g.isVisited(i))  
        {
            return false;
        }

    }
    return true;
}
void findSpanningForest(graph &g, graph &sf)
// Create a graph sf that contains a spanning forest on the graph g.  
{
    if (isConnected(g) && !isCyclic(g))
    {
        sf = g;
    }
    else
    {
        if (g.numNodes() > 0)
            sf.addNode(g.getNode(0));
        for(int i = 1; i < g.numNodes(); i++)
        {
            sf.addNode(g.getNode(i));
            for (int x = 0; x < g.numNodes(); x++)
            {
                if (g.isEdge(i, x))
                {
                    sf.addEdge(i, x);
                    if(isCyclic(sf))
                        sf.removeEdge(i,x);
                }
            }       
        }        

    }

}



int main()
{
   char x;
   ifstream fin;
   stack <int> moves;
   string fileName;
   
   // Read the name of the graph from the keyboard or
   // hard code it here for testing.
   
   fileName = "graph1.txt";

   //   cout << "Enter filename" << endl;
   //   cin >> fileName;
   
   fin.open(fileName.c_str());
   if (!fin)
   {
      cerr << "Cannot open " << fileName << endl;
      exit(1);
   }

   try

   {
      cout << "Reading graph" << endl;
      graph g(fin);

      cout << g;
	    
      bool connected;
      bool cyclic;

      connected = isConnected(g);
      cyclic = isCyclic(g);

      if (connected)
	 cout << "Graph is connected" << endl;
      else
	 cout << "Graph is not connected" << endl;

      if (cyclic)
	 cout << "Graph contains a cycle" << endl;
      else
	 cout << "Graph does not contain a cycle" << endl;

      cout << endl;
     
      cout << "Finding spanning forest" << endl;

      // Initialize an empty graph to contain the spanning forest
      graph sf(g.numNodes());
      findSpanningForest(g,sf);

      cout << endl;

      cout << sf;

      cout << "Spanning forest weight: " << sf.getTotalEdgeWeight()/2 << endl;

      connected = isConnected(sf);
      cyclic = isCyclic(sf);

      if (connected)
	 cout << "Graph is connected" << endl;
      else
	 cout << "Graph is not connected" << endl;

      if (cyclic)
	 cout << "Graph contains a cycle" << endl;
      else
	 cout << "Graph does not contain a cycle" << endl;

      cout << endl;
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

