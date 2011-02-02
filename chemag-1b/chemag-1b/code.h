/** Project 1a code.h
  * Jie Chen * Patrick Maguire
  *
  * This file is the interface for the Code class. 
  * It declares the public contstructor and methods checkCorrect, and print
  * It also declares the private data member seq.
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
<<<<<<< HEAD
	int getLength() const { return length; }
=======
>>>>>>> e726132da46dfc314eb21aa391f71b152fcfe242
    // associate the output operator with the Code class so we have 
    // access to data member
    friend ostream &operator<<(ostream &out, const Code &c);


private:
	int length;
    vector<int> seq;
    vector<int> count;
};
