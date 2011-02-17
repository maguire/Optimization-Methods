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
	while (fins.good())
	{
	    getline(myfins, line);
	    wordLst.push_back(line);
	}
    }
    else
    {
	cout << "warning: was unable to open dictionary";
    }
}
    
bool Dictionary::lookup(string s)
// search the dictionary to see if the input string is a word
// returns a bool
{
    vector<string> iter = wordLst.begin();
    
    while (iter != wordLst.end() && *iter != s)
    {}

    return iter != wordLst.end();
}
