/** Project 3b ChemagHashTableDictionary.h
  * Jie Chen * Patrick Maguire
  *
  *
  * This file contains the interface for the Dictionary class
  **/

#include "ChemagHashTablDictionary.h"

using namespace std;

ChemagHashTableDictionary::ChemagHashTableDictionary(string file)
{
	init(file);
}
bool ChemagHashTableDictionary::lookup(string word) const
{
	//
}

void ChemagHashTableDictionary::put(char key, const ChemagNode &value)
{
	topLevel[key-'a'] = value;
}
ChemagNode ChemagHashTableDictionary::get(string key) const
{
	if (topLevel[key-'a'])
	{
		return topLevel[key-'a'];
	}
	else 
	{
		return NULL;
	}
}

void ChemagHashTableDictionary::init(string filename)
{
	string line;
    ifstream fins;
    fins.open(filename.c_str());

    if (fins.is_open())
    {
        while (getline(fins, line))
        {
            insertStringIntoHash(line);
        }
        fins.close();
    }
    else
    {
        throw fileOpenError(filename);
    }
}

void ChemagHashTableDictionary::insertStringIntoHash(string word)
{
	ChemagHashTableDictionary currentLevel = *this;
	for(int i = 0; i < word.length; i++)
	{
		
		ChemagNode currentNode = currentLevel.get(word[i]);
		if (!currentNode)
		{
			currentNode = ChemagNode(word[i], false);
			currentLevel.put(word[i], currentNode);
		}
		if (i == word.length - 1)
		{
			currentNode.setInDict(true);
		}
		else 
		{
			currentLevel = currentNode.getNextLevel();
		}
	}
}

