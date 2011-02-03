/** Project 1b code.cpp
  * Jie Chen * Patrick Maguire
  *
  * This file is the implementation for the Code class.
  * It defines the public contstructor and methods checkCorrect, print, and
  * checkIncorrect. It also defines the overloaded operator << for the Code
  * class. 
  */

#include <iostream>
#include <vector>
#include "d_random.h"
#include "d_except.h"
#include "code.h"

using namespace std;

Code::Code (int n, int m) : count (m, 0), length(n), range(m)
//public constructor which takes in the length of the mastermind code n, and
// the range of the appropriate values m
{
    if (n < 0)
    {
        throw rangeError("Cannot create code with negative length.");
    }
    if (m < 0)
    {
        throw rangeError("Cannot create code with a negative range.");
    }

    randomNumber genRandom;

    for (int i = 0; i < n; i++)
    {
        int temp = genRandom.random (m);
        seq.push_back (temp);
        // increment the count at index equal to the random number 
        // i.e. count[7] = 1 + count[7]
        count[temp]++;
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

int Code::checkCorrect (const vector<int> &guess) const
//public method to check how many values are at the same position in both the
// given guess and this mastermind code sequence
{
    int num_aligned = 0;

    for (int i = 0; i < guess.size(); i++)
    {
        if (guess[i] == seq[i])
        {
            num_aligned++;
        }
    }

    return num_aligned;
}

int Code::checkIncorrect (const vector<int> &guess) const
// function to check the number of digits that is correct but in the 
// wrong place.  no digit is counted twice
{
    int num_incorrect = 0;

    //copy the count array for this pass of checking so that we do not destroy
    // the original count values
    vector<int> localCount = count;

    for (int i = 0; i < guess.size(); i++)
    {
        // if the count at the ith number in the guess does not equal zero
        // and ith guess number is not equal to the ith number of the answer
        if (localCount[guess[i]] && guess[i] != seq[i])
        {
            num_incorrect++;
            localCount[guess[i]]--;
        }
        else if (guess[i] == seq[i])
        {
            localCount[guess[i]]--;
        }
    } // END for

    return num_incorrect;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
// << operator overload for vector of a given type (T)
{
    for (int i = 0; i < v.size(); i++)
    {
        out << v[i] << ' ';
    }
    return out;
}


ostream &operator<<(ostream &out, const Code &c)
// << operator overload for Code objects
{
    return out << c.seq;
}

