/** Project 3b ChemagHashTableDictionary.h
  * Jie Chen * Patrick Maguire
  *
  *
  * This file contains the interface for the Dictionary class
  **/

#include <vector>
#include <string>
#include "Dictionary.h"

using namespace std;

class ChemagHashTableDictionary : public Dictionary
{
public:
    ChemagHashTableDictionary(string file = "dictionary");
    bool lookup(string word) const;
	void put(string key, ChemagNode value);
	void get(string key) const;
	
private:
	int hash(string key) const;
    void init(string filename);
	vector<ChemagNode> topLevel;
};
