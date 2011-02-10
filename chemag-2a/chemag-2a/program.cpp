/** Project 2a program.cpp
  * Jie Chen * Patrick Maguire
  * 
  * This file is the entry point for the project. Defines the main function
  * to run the program for testing.
  * 
  **/

#include <iostream>
#include "d_except.h"
#include "Deck.h"
using namespace std;

int main()
// entry point for the program, handles exceptions thrown during execution
{
    try
    {
        cout << Deck();
    }
    catch (rangeError &re)
    {
        cout << re.what() << endl;
    }

}
