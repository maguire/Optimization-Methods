/** Project 3b ChemagHashTableDictionary.h
  * Jie Chen * Patrick Maguire
  *
  *
  * This file contains the interface for the ChemagHashTableDictionary class
  *
  * This class inherits from Dictionary, the dictionary is stores as a
  * multi-leveled tree like structure
  **/

#ifndef ChemagHashTableDictionary_H
#define ChemagHashTableDictionary_H

#include <vector>
#include <string>
#include "Dictionary.h"

using namespace std;

template <class T>
class ChemagHashTableDictionary 
{
public:
    ChemagHashTableDictionary(string file = "dictionary");
    vector<string> lookup(string word) const;
	void put(char key, const T &value);
	T get(char key) const;
	
private:
	int hash(string key) const;
    void init(string filename);
    
	vector<T> topLevel;
};

#endif
