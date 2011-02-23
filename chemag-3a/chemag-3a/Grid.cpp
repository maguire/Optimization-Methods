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

vector<string> tokenize(const string &str, char delimit = ' ')
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
        mx = matrix<string>(atoi(vs[0].c_str()), atoi(vs[1].c_str()));
    }
    fins.close();
}
