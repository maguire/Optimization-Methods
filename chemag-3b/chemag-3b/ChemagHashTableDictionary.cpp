/** Project 3b ChemagHashTableDictionary.h
  * Jie Chen * Patrick Maguire
  *
  *
  * This file contains the interface for the Dictionary class
  **/
#include <fstream>
#include "d_except.h"
#include "ChemagNode.h"
#include "ChemagHashTableDictionary.h"

using namespace std;
template <class T>
ChemagHashTableDictionary<T>::ChemagHashTableDictionary(string file)
{
	init(file);
}
template <class T>
vector<string> ChemagHashTableDictionary<T>::lookup(string word) const
{
	//find all the words in this hashtree that are a part of this word

}

template <class T>
void ChemagHashTableDictionary<T>::put(char key, const T &value)
{
	topLevel[key-'a'] = value;
}

template <class T>
T ChemagHashTableDictionary<T>::get(char key) const
{
    return topLevel[key-'a'];
}
template <class T>
void ChemagHashTableDictionary<T>::init(string filename)
{
	string line;
    ifstream fins;
    fins.open(filename.c_str());

    if (fins.is_open())
    {
        while (getline(fins, line))
        {
            insertStringIntoHash(line, *this);
        }
        fins.close();
    }
    else
    {
        throw fileOpenError(filename);
    }
}


void insertStringIntoHash(const string &word, ChemagHashTableDictionary<ChemagNode> &currentLevel)
{
    string wordSoFar = "";
	for(int i = 0; i < word.length(); i++)
	{
        
		wordSoFar = wordSoFar + word[i];
		ChemagNode currentNode = currentLevel.get(word[i]);
		if (currentNode.getWord() != "")
		{
			currentNode = ChemagNode(wordSoFar, false);
			currentLevel.put(word[i], currentNode);
		}
		if (i == word.length() - 1)
		{
			currentNode.setInDict(true);
		}
		else 
		{
			currentLevel = currentNode.getNextLevel();
		}
	}
}

