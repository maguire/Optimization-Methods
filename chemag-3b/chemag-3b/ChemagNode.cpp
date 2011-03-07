/** Project 3b ChemagHashTableDictionary.h
  * Jie Chen * Patrick Maguire
  *
  *
  * This file contains the interface for the Dictionary class
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

bool Chemag::getInDict() const
{
	return this->inDict;
}

ChemagHashTableDictionary& ChemagNode::getNextLevel() const
{
	return this->nextLevel;
}
