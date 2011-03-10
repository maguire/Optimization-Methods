/** Project 3b ChemagNode.h
  * Jie Chen * Patrick Maguire
  *
  *
  * This file contains the interface for the ChemagNode class
  *
  * represents a node in the tree structure
  **/

#ifndef ChemagNode_H
#define ChemagNode_H

#include <string>
#include "ChemagHashTableDictionary.h"

using namespace std;

class ChemagNode
{
public:
    ChemagNode(string word, bool inDict);
	string getWord() const;
	bool getInDict() const;
	ChemagHashTableDictionary &getNextLevel() const;

private:
	string word;
	bool inDict;
	ChemagHashTableDictionary nextLevel;
};

#endif