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

vector<string> tokenize(const string &str, char delimit = ' ')
// given a string split it into tokens by the given delimiter
// this is a global function
{
    vector<string> tokens;
    int prev = 0;

    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (str[i] == delimit)
        {
            tokens.push_back(str.substr(prev, i - prev));
            prev = i + 1; // skip the delimiter
        }
    }

    // the loop will skip the last token make sure that gets in the vector
    tokens.push_back(str.substr(prev, str.length() - prev));

    return tokens;
}

Grid::Grid(string in_fd)
// public Grid constructor
// given a file, read the file and create a matrix according to the file
{
    string line;
    ifstream fins;
    fins.open(in_fd.c_str());
    string s;

    if (fins.is_open())
    {
        //read the first line, which tells us the size of the matrix
        getline(fins, line);
        vector<string> vs = tokenize(line);
        _size = atoi(vs[0].c_str());
        mx = matrix<string>(atoi(vs[0].c_str()), atoi(vs[1].c_str()));
        
        for (int i = 0; i < _size; i++)
        {
            getline(fins, line);
            vs = tokenize(line);
            for (int j = 0; j < _size; j++)
            {
                mx[i][j] = vs[j];
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
