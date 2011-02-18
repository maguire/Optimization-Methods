/** Project 3a Grid.cpp
  * Jie Chen * Patrick Maguire
  *
  * This file contains the implmentation for the Grid class
  *    - defines the public grid constructor
  *
  **/

#include <fstream>
#include <iostream>
#include "Grid.h"

Grid::Grid(string in_fd)
{
    string line;
    ifstream fins;
    fins.open(in_fd.c_str());

    if (fins.is_open())
    {
	//read the first line, which tells us the size of the matrix
	getline(fins, line);
	cout << line << endl;	
    }
    fins.close();
}
