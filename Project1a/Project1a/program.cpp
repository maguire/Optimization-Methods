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

static vector<int> makeGuess(const int* arr, int len)
// create a vector given an arr of ints
// this is a function private to program.cpp and used only for generating
// guess
{
    vector<int> v(arr, arr + len);
    cout << "guess: ";
    
    //print the guess sequence
    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << ' ';
    
    cout << '\n';
    return v;
}

int main()
{
    int length = 5;
    int range = 10;

    Code code1(length,range);
    //print the code
    cout << "Code: ";
    code1.print();
    cout << '\n';
    
    // 2d int array to store the 3 guess 
    int codeArr[3][5] = {{ 1, 2, 3, 4, 5 }, 
                         { 3, 7, 4, 9, 2 }, 
                         { 8, 2, 6, 0, 1 }};

    // loop to make 3 guess
    for (int i = 0; i < 3; i++)
    {
        vector<int> guess = makeGuess(codeArr[i], 5);
        cout << "number of extactly correct: ";
        cout << code1.checkCorrect(guess) << '\n';
    }
}