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

void ChemagNode::setInDict(bool inDict)
{
    this->inDict = inDict;
}

bool ChemagNode::getInDict() const
{
	return this->inDict;
}

ChemagHashTableDictionary<ChemagNode> &ChemagNode::getNextLevel() 
{
	return this->nextLevel;
}
