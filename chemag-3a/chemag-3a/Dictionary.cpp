/** Project 3a Dictionary.cpp
  * Jie Chen * Patrick Maguire
  *
  * This file contains the implementation for the Dictionary class
  *   -defines the public constructor
  *   -defines the lookup function
  */

#include <fstream>
#include <iostream>
#include "d_except.h"
#include "Dictionary.h"


Dictionary::Dictionary(string filename) : wordLst(vector<string>())
// default public constructor for the Dictionary class
// reads the dictionary file and store all the words in a vector
{
    init(filename);
}


void Dictionary::init(string filename)
// called by the Dictionary constructor
// reads the dictionary file and store all the words in a vector
{
    string line;
    ifstream fins;
    fins.open(filename.c_str());

    if (fins.is_open())
    {
        while (getline(fins, line))
        {
            wordLst.push_back(line);
        }
        fins.close();
    }
    else
    {
        throw fileOpenError(filename);
    }
}

bool Dictionary::lookup(string s) const
// search the dictionary to see if the input string is a word
// returns a bool
{
    for (int i = 0; i < wordLst.size(); i++)
    {
        if (wordLst[i] == s)
        {
            return true;
        }
    }
    return false;
}
