#include <iostream>
#include <vector>

#include "d_random.h"

#include "code.h"

using namespace std;

code::code(int n, int m)
{
    randomNumber genRandom;

    for (int i = 0; i < n; i++)
    {
        int temp = genRandom.random(m);
        seq.push_back(temp);
    }
}

void code::print() const
{
    for (int i = 0; i < seq.size(); i++)
        cout << seq[i] << ' ';

    cout << '\n';
}

int code::checkCorrect(vector<int> guess) const
{
    int size = seq.size();
    int num_aligned = 0;
    int num_correct = 0;

    for (int i = 0; i < size; i++)
    {
        if(guess[i] == seq[i])
        {
            num_aligned++;
        }
    }
    return num_aligned++;
}