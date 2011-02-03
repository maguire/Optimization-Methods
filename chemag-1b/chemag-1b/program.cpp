/** Project 1b program.cpp
  * Jie Chen * Patrick Maguire
  *
  * This file is the entry point for the project. It defines the main method
  * used to test the code class, specifically checkCode.
  */

#include <iostream>
#include <vector>
#include "d_except.h"
#include "Mastermind.h"

using namespace std;

int main()
//program entry point, creates a mastermind object and starts a single game
//this is where we will catch any exceptions
{
    try
    {
        Mastermind master(5, 10);
        master.playGame();
    }
    catch (rangeError &re)
    {
        cout << re.what() << endl;
    }
}


