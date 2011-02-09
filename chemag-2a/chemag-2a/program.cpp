#include <iostream>
#include "d_except.h"
#include "Deck.h"
using namespace std;

int main()
{

    try
    {
        cout << Deck();
    }
    catch (rangeError &re)
    {
        cout << re.what() << endl;
    }

}
