#include <iostream>
#include <vector>
#include "d_random.h"

using namespace std;

class code
{
    public:
        code(int n, int m);
        int checkCorrect(vector<int> guess) const;
        void print() const;

    private:
        vector<int> seq;
};

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

int main()
{
    for(int x = 0; x < 10; x++){
        code c(5,10);
        vector<int> v(4,5);
        v.push_back(9);
        c.checkCorrect(v);
        c.print();

    }
}
