#include <iostream>
#include <vector>
#include "Mastermind.h"

using namespace std;

Mastermind::Mastermind(int n, int m) : secretCode(n, m), length(n), range(10)
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
{}


void Mastermind::printFeedback(const int correct, const int incorrect) const
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
{
    vector<int> guess = vector<int>(5, 0);
    for (int i = 0; i < guess.size(); i++)
    {
        cout << "Add another guess to the sequence: ";

        cin >> guess[i];
        if (guess[i] >= range || guess[i] < 0)
        {
            throw rangeError("You have given a value outside the range");
        }
    }
    return guess;
}
void Mastermind::playGame() const
{
    cout << secretCode << endl;
    const int numGuesses = 10;

    for (int i = 0; i < numGuesses; i++)
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

