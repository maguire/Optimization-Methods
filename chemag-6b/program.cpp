// Project 6b Chemag - Patrick Maguire and Jie Chen
// Solution for Prim's minimum spanning tree algorithm

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
#include <queue>
#include <stdlib.h>

using namespace std;

int const NONE = -1;  // Used to represent a node that does not exist

class CompareEdge
{

public:
    bool operator() (edge &e1, edge &e2)
    {
	    return e2.getWeight() < e1.getWeight();
    }

};

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

void exploreDFS(int cur, int from, graph &g, bool &cyclic)
// implement a version of Depth First Search that uses a stack data structure
// and does not use recursion
{
    
    int top = cur;
    g.mark(top);
    vector<int> lst = getNeighbors(top, g);
    for (int i = 0; i < lst.size(); i++)
    {
	if (from == lst[i])
	    continue;

     	if (g.isMarked(lst[i]))
	{
	    cyclic = true;
	}
	else if (!g.isVisited(lst[i]))
	{
	    exploreDFS(lst[i], top, g, cyclic);
	}
    }
    g.unMark(top);
    g.visit(top);
}

bool isCyclic(graph &g)
// Returns true if the graph g contains a cycle.  Otherwise, returns false.
{
    g.clearVisit();
    g.clearMark();
    bool cyclic = false;
    for (int i = 0; i < g.numNodes(); i++)
    {
        if (!g.isVisited(i))
            exploreDFS(i, i, g, cyclic);
    }

    g.clearVisit();
    g.clearMark();

    return cyclic;
}
bool isConnected(graph &g)
// Returns true if the graph g is connected.  Otherwise returns false.
{
    g.clearVisit();
    g.clearMark();
    bool c = false;
    exploreDFS(0, 0, g, c);
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
        // add all the nodes from g to sf
        for (int i = 0; i < g.numNodes(); i++)
        {
            sf.addNode(g.getNode(i));
        }

        // build the sf
        for(int i = 0; i < g.numNodes(); i++)
        {
            for (int x = 0; x < g.numNodes(); x++)
            {
                if (g.isEdge(i, x) && !sf.isEdge(i, x))
                {
                    sf.addEdge(i, x, g.getEdgeWeight(i, x));
                    sf.addEdge(x, i, g.getEdgeWeight(x, i));

                    if(isCyclic(sf))
                    {
                        sf.removeEdge(x,i);
                        sf.removeEdge(i,x);
                    }
                }
            }       
        }        
    }
}

void findSF(graph &g, graph &sf, int start)
//finds a minimum spanning tree in the connected given graph 
{
    priority_queue<edge, vector<edge>, CompareEdge> pq;
    vector<int> lst = getNeighbors(start, g);
    for (int i = 0; i < lst.size(); i++)
    {
	    pq.push(g.getEdge(start, lst[i]));
	    g.mark(start, lst[i]);
    }
    g.visit(start);

    int src, dst, w;
    edge top;

    while (!pq.empty())
    {
        top = pq.top();
        pq.pop();
        src = top.getSource();
        dst = top.getDest();
        w = top.getWeight();
        if (!sf.isEdge(src, dst))
        {
            sf.addEdge(src, dst, w);
            sf.addEdge(dst, src, w);
            
            if (isCyclic(sf))
            {
                sf.removeEdge(src, dst);
                sf.removeEdge(dst, src);
            }
            else
            {
                g.visit(src);
                lst = getNeighbors(dst, g);
                for (int i = 0; i < lst.size(); i++)
                {
                    if (!g.isMarked(dst, lst[i]))
                    {
                        pq.push(g.getEdge(dst, lst[i]));
                        g.mark(dst, lst[i]);
                    }
                }
            }
        }
    }
}

void prim(graph &g, graph &sf)
//finds a minimum spanning forrest, including unconnected graphs
{
    for (int i = 0; i < g.numNodes(); i++)
    {
        sf.addNode(g.getNode(i));
    }
    
    for (int i = 0; i < g.numNodes(); i++)
    {
        if (!g.isVisited(i))
        {
            findSF(g, sf, i);
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
   
   fileName = "graph4.txt";

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
      graph fake;
      findSpanningForest(g,fake);

      graph sf;
      prim(g,sf);
        

      cout << endl;

      cout << sf;

      
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
      cout << "Spanning forest weight: " << fake.getTotalEdgeWeight()/2 << endl;

      cout << "Minimum Spanning forest weight: " << sf.getTotalEdgeWeight()/2 << endl;
      cout << "Spanning forest difference : " << fake.getTotalEdgeWeight()/2 - sf.getTotalEdgeWeight()/2 << endl;
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

