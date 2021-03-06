/** Project 1a code.cpp
  * Jie Chen * Patrick Maguire
  *
  * This file is the implementation for the Code class. 
  * It defines the public contstructor and methods checkCorrect, and print
  */

#include <iostream>
#include <vector>
#include "d_random.h"
#include "code.h"

using namespace std;

Code::Code(int n, int m)
//public constructor which takes in the length of the mastermind code n, and 
// the range of the appropriate values m
{
    randomNumber genRandom;

    for (int i = 0; i < n; i++)
    {
        int temp = genRandom.random(m);
        seq.push_back(temp);
    }
}

void Code::print() const
//public method to send this mastermind code sequence to the output buffer
{
    for (int i = 0; i < seq.size(); i++)
    {
        cout << seq[i] << ' ';
    }

    cout << '\n';
}

int Code::checkCorrect(const vector<int> &guess) const
//public method to check how many values are at the same position in both the
// given guess and this mastermind code sequence
{
    int num_aligned = 0;

    for (int i = 0; i < guess.size(); i++)
    {
        if(guess[i] == seq[i])
        {
            num_aligned++;
        }
    }
    return num_aligned;
}