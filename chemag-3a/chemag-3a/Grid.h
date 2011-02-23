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
    matrix<string> getMatrix() const
    {
        return mx;
    }
    void print();

private:
    matrix<string> mx;

};
