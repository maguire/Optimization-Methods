/** Project 1b code.h
  * Jie Chen * Patrick Maguire
  *
  * This file is the interface for the Code class.
  * It declares the public contstructor and methods checkCorrect, and print
  * It also declares the private data members (vector<int>seq,count and 
  * (int)length,range.
  */
#include <vector>

using namespace std;

class Code
{

public:
    Code(int n, int m);
    int checkCorrect(const vector<int> &guess) const;
    int checkIncorrect(const vector<int> &guess) const;
    void print() const;
    // return the length of the code
    int getLength() const { return length; }
    // return the range of the digits in the code (0 indexed)
    int getRange() const { return range; }
    // associate the output operator with the Code class so we have
    // access to data member
    friend ostream &operator<<(ostream &out, const Code &c);


private:
    int length, range;
    vector<int> seq;
    vector<int> count;
};
