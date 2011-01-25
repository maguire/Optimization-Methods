/** Project 1a program.cpp
  * Jie Chen * Patrick Maguire
  *
  * This file is the entry point for the project. It defines the main method
  * used to test the code class, specifically checkCode and print methods.
  */
#include <iostream>
#include <vector>

#include "code.h"

using namespace std;

int main()
{
    Code code1(5,10);
    int codeValues[] = { 1, 2, 3, 4, 5 };
    //initialize the guess vector of the values of the int array codeValues
    vector<int> guess(codeValues, 
        codeValues + sizeof(codeValues)/sizeof(*codeValues));

    //print the code and the number of correct with the given guess
    cout << "Code ";
    code1.print();
    cout << " has " << code1.checkCorrect(guess) << " guess correct" << "\n";

}