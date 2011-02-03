/** Project 1b Mastermind.cpp
  * Jie Chen * Patrick Maguire
  *
  * This file is the implementation for the Mastermind class.
  * It defines the public contstructors and methods playGame, printFeedback,and
  * readInput.
  */
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Mastermind.h"

using namespace std;

Mastermind::Mastermind(int n, int m) : secretCode(n, m)
// public constructor for creating a Mastermind object with a 
// a secretCode (code object) with length n and digit range m
{}

Mastermind::Mastermind() : secretCode(5, 10)
// default Mastermind constructor that uses 5 and 10 as the default
// parameters to create the code object
{}


void Mastermind::printFeedback(const int correct, const int incorrect) const
// print the computer feedback 
// (number of correct digits, and number of correct digit in the wrong place)
// the data is passed in as parameters
{
    if (correct == secretCode.getLength())
    {
        cout << "You guessed it right!" << endl;
    }
    else
    {
        cout << "You got " << correct << " correct and " << incorrect <<
             " correct but misaligned." << endl;
    }
}

vector<int> Mastermind::readInput() const
// read user guess from the console
// if the user inputs char 'e' we want to exit
{
    vector<int> guess = vector<int>(secretCode.getLength(), 0);
    for (int i = 0; i < guess.size(); i++)
    {
        cout << "Add another guess to the sequence (or type '(e)xit'): ";

        // set the length of the input char array by figuring out how many char
        // should be in the input
        int arrayLength = 1;
        int x = secretCode.getRange();
        while( x > 10 )
        {
            x /= 10; 
            arrayLength++; 
        }
        // create a char array by allocating memory of arrayLength + '\0'
        char *input = new char[arrayLength+1];
        cin >> input;

        if (input[0] == 'e' )
        {
            exit(0);
        }
        else if (atoi(input) >= secretCode.getRange() || input[0] < '0' || 
            input[0] > '9')
        {
            throw rangeError("You have given a value outside the range");
        }
        else 
        {
            guess[i] = atoi(input);
        }
        //clean up input array
        delete [] input;
        input = NULL;
    }// END for
    return guess;
}// END readInput()

void Mastermind::playGame() const
// start a mastermind game, the user is allowed 10 guess
{
    cout << "the code is: " << secretCode << endl;
    
    for (int i = 0; i < NUM_GUESSES; i++)
    {
        const vector<int> guess = readInput();
        const int numCorrect = secretCode.checkCorrect(guess);
        const int numIncorrect = secretCode.checkIncorrect(guess);
        printFeedback(numCorrect, numIncorrect);
        if (numCorrect == secretCode.getLength())
        {
            return;
        }
    }

    cout << "You have lost. Try again tomorrow when you are smarter." << endl;
}

