#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Mastermind.h"

using namespace std;

Mastermind::Mastermind(int n, int m) : secretCode(n, m), length(n), range(10)
// public constructor for creating a Mastermind object with a 
// a secretCode (code object) with length n and digit range m
{
    if (n < 0)
    {
        throw rangeError("Cannot create code with negative length.");
    }
    if (m < 0)
    {
        throw rangeError("Cannot create code with a negative range.");
    }
}

Mastermind::Mastermind() : secretCode(5, 10), length(5), range(10)
// default Mastermind constructor that uses 5 and 10 as the default
// parameters to create the code object
{}


void Mastermind::printFeedback(const int correct, const int incorrect) const
// print the computer feedback 
// (number of correct digits, and number of correct digit in the wrong place)
// the data is passed in as parameters
{
    if (correct == length)
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
    vector<int> guess = vector<int>(5, 0);
    for (int i = 0; i < guess.size(); i++)
    {
        cout << "Add another guess to the sequence (or type '(e)xit'): ";
        char input[1];
        cin >> input;
        if (input[0] == 'e')
        {
            exit(0);
        }
        else if (atoi(input) >= range || input[0] < '0')
        {
            throw rangeError("You have given a value outside the range");
        }
        else 
        {
            guess[i] = atoi(input);
        }
    }
    return guess;
}

void Mastermind::playGame() const
// start a mastermind game, the user is allowed 10 guess
{
    cout << secretCode << endl;
    const int numGuesses = 10;

    for (int i = 0; i < numGuesses; i++)
    {
        const vector<int> guess = readInput();
        const int numCorrect = secretCode.checkCorrect(guess);
        const int numIncorrect = secretCode.checkIncorrect(guess);
        printFeedback(numCorrect, numIncorrect);
        if (numCorrect == length)
        {
            return;
        }
    }

    cout << "You have lost. Try again tomorrow when you are smarter." << endl;
}

