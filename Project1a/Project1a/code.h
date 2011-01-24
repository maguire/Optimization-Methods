#include <vector>


using namespace std;

class Code
{

public:
    Code(int n, int m);
    int checkCorrect(vector<int> guess) const;
    void print() const;

private:
    vector<int> seq;
};