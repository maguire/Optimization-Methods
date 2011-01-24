#include <vector>

#include "code.h"

using namespace std;

int main()
{
    for(int x = 0; x < 10; x++){
        Code c(5,10);
        vector<int> v(4,5);
        v.push_back(9);
        c.checkCorrect(v);
        c.print();

    }
}