/** Project 3a Dictionary.cpp
  * Jie Chen * Patrick Maguire
  *
  * This file contains the implementation for the Dictionary class
  *   -defines the public constructor
  *   -defines the lookup function
  */

#include <fstream>
#include <iostream>
#include "Dictionary.h"

Dictionary::Dictionary() : wordLst(vector<string>())
// default public constructor for the Dictionary class
// reads the dictionary file and store all the words in a vector
{
    string line;
    ifstream fins;
    fins.open("dictionary");

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
        cout << "warning: was unable to open dictionary";
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
