/** Project 1a program.cpp
  * Jie Chen * Patrick Maguire
  *
  * This file is the entry point for the project. It defines the main method
  * used to test the code class, specifically checkCode and print methods.
  */

#include <iostream>
#include <vector>
#include "d_except.h"
#include "Mastermind.h"


using namespace std;

static vector<int> makeGuess(const int arr[], int len)
// create a vector given an array of ints
// this is a function private to program.cpp and used only for generating
// guess -- represented by int vector --
{
    vector<int> v(arr, arr + len);
    cout << "making guess: ";
    
    //print the guess sequence
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    
    cout << '\n';
    return v;
}

int main()
//program entry point, creates a code and checks some guesses against it
{
    const int length = 5;
    const int range = 10;
    const int numGuesses = 3;

    Code code1(length,range);
    //print the code
    cout << "Code: " << code1;
    cout << '\n';
    
    // 2d int array to store the hardcoded guesses 
    const int codeArr[numGuesses][length] = {{ 1, 2, 3, 4, 5 }, 
                                             { 3, 7, 4, 9, 2 }, 
                                             { 8, 2, 6, 0, 1 }};

    // loop to make numGuesses
    for (int i = 0; i < numGuesses; i++)
    {
        vector<int> guess = makeGuess(codeArr[i], length);
        cout << "number of extactly correct: ";
        cout << code1.checkCorrect(guess) << '\n';

        cout << "number of correct in wrong place: ";
        cout << code1.checkIncorrect(guess) << '\n';
    }


	try
	{
		Mastermind master;
		master.playGame();
	}
	catch(rangeError &re)
	{
		cout << re.what();
	}
}
