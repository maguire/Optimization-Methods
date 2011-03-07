/** Project 3b ChemagHashTableDictionary.h
  * Jie Chen * Patrick Maguire
  *
  *
  * This file contains the interface for the Dictionary class
  **/


using namespace std;

class ChemagNode
{
public:
    ChemagNode(string word, bool inDict);
	string getWord() const;
	bool getInDict() const;
	ChemagHashTableDictionary& getNextLevel() const;

private:
	string word;
	bool inDict;
	ChemagHashTableDictionary nextLevel;
};