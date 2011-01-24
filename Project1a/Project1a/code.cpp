#include <iostream>
#include <vector>

#include "d_random.h"

#include "code.h"

using namespace std;

Code::Code(int n, int m)
{
    randomNumber genRandom;

    for (int i = 0; i < n; i++)
    {
        int temp = genRandom.random(m);
        seq.push_back(temp);
    }
}

void Code::print() const
{
    for (int i = 0; i < seq.size(); i++)
        cout << seq[i] << ' ';

    cout << '\n';
}

int Code::checkCorrect(vector<int> guess) const
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