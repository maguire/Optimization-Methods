#include "d_except.h"
#include "code.h"

using namespace std;

class Mastermind
{
public:
    Mastermind(int n, int m);
    Mastermind();
    void playGame() const;

private:
    int length, range;
    vector<int> readInput() const;
    void printFeedback(const int correct, const int incorrect) const;
    Code secretCode;
};
