#include <string>
#include <iostream>

using namespace std;

class Card
{
public:
    Card(int, string);   
    // getter for value
    int getValue() { return value; }
    // setter for value
    void setValue(int val) { value = val; }
    // getter for suit
    string getSuit() { return suit; }
    // setter for suit
    void setSuit(string s) { suit = s; }
    // associate the output overload for Card object to grant access
    // to private data member
    friend ostream &operator<<(ostream &out, const Card &c);
private:
    int value;
    string suit;
};
