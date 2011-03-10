/** Project 3b ChemagHashTableDictionary.h
  * Jie Chen * Patrick Maguire
  *
  *
  * This file contains the implementation of the ChemagNode class
  *   - defines the public constructor
  *   - defines getWord
  *   - defines getInDict
  *   - defines getNextLevel
  **/

#include "ChemagNode.h"

using namespace std;

ChemagNode::ChemagNode(string word, bool inDict) 
{
	this->word = word;
	this->inDict = inDict;
}

string ChemagNode::getWord() const
{
	return this->word;
}

bool ChemagNode::getInDict() const
{
	return this->inDict;
}

ChemagHashTableDictionary &ChemagNode::getNextLevel() const
{
	return this->nextLevel;
}
