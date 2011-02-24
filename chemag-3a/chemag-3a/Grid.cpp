/** Project 3a Grid.cpp
  * Jie Chen * Patrick Maguire
  *
  * This file contains the implmentation for the Grid class
  *    - defines the public grid constructor
  *
  **/

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "Grid.h"

Grid::Grid(string in_fd)
// public Grid constructor
// given a file, read the file and create a matrix according to the file
{
    ifstream fins;
    fins.open(in_fd.c_str());

    if (fins.is_open())
    {
        string sizex, sizey;
        fins >> sizex >> sizey;
        _size = atoi(sizex.c_str());
        mx = matrix<string>(atoi(sizex.c_str()), atoi(sizey.c_str()));
        
        for (int i = 0; i < _size; i++)
        {
            for (int j = 0; j < _size; j++)
            {
                fins>>mx[i][j];
            }
        }
    }
    fins.close();
}

// non-constant version. provides general access to Grid
// elements
vector<string>& Grid::operator[] (int i)
{
   if (i < 0 || i >= _size)
      throw indexRangeError(
	 "Grid: invalid row index", i, _size);

   return mx[i];
}

// constant version.  can be used with a constant object.
// does not allow modification of a Grid element
const vector<string>& Grid::operator[] (int i) const
{
   if (i < 0 || i >= _size)
      throw indexRangeError(
	 "Grid: invalid row index", i, _size);

   return mx[i];
}

void Grid::print()
// not require by spec, for sanity check purpose only
// print a grid
{
    for (int i = 0; i < mx.rows(); i++)
    {
        for (int j = 0; j < mx.cols(); j++)
        {
            cout << mx[i][j] << ' ';
        }
        cout << endl;
    }
}
