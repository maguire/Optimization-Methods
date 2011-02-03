/** Project 1b Mastermind.h
  * Jie Chen * Patrick Maguire
  *
  * This file is the interface for the Mastermind class.
  * It declares the public contstructor and methods playGame, printFeedback,and
  * readInput. It declares the private data member (Code)secretCode
  */
#include "d_except.h"
#include "code.h"

using namespace std;

class Mastermind
{
public:
    Mastermind(int n, int m);
    Mastermind();
    void playGame() const;
    Code getSecretCode() const { return secretCode; }

private:
    Code secretCode;
    static const int NUM_GUESSES = 10;
    vector<int> readInput() const;
    void printFeedback(const int correct, const int incorrect) const;

};
