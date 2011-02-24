/** Project 3a Grid.h
  * Jie Chen * Patrick Maguire
  *
  * This file contains the interface for the Grid class
  *
  **/

#include <string>
#include "d_matrix.h"

using namespace std;

class Grid
{
public:
    Grid(string in_fd);
   
     vector<string>& operator[] (int i);
    // index operator.
    // Precondition: 0 <= i < _size. a violation of this
    // precondition throws the indexRangeError exception.
    // Postcondition: if the operator is used on the left-hand
    // side of an assignment statement, an element of row i 
    // is changed
    
    const vector<string>& operator[](int i) const;
    // version for constant objects
   
    int size() const { return _size; }
    void print();

private:
    matrix<string> mx;
    int _size;
};
