/** Project 3b VecotrDictionary.h
  * Jie Chen * Patrick Maguire
  *
  *
  * This file contains the interface for the VecotrDictionary class
  * 
  * This class uses a vector to store a dictionary
  **/

#include <vector>
#include <string>
#include "Dictionary.h"

using namespace std;

class VectorDictionary : public Dictionary
{
public:
    VectorDictionary(string file = "dictionary");
    virtual bool lookup(string word) const;

protected:
    vector<string> wordLst;
    void print();

private:
    void init(string filename);
};
