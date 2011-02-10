/** Project 2a Card.h
  * Jie Chen * Patrick Maguire 
  *
  * This file contains the interface for the Card class and the enum
  * of type Suit
  * 
  * It declares the public constructor, the getter and setters for the data 
  * members.
  * 
  * It declares the private data members value and suit
  *
  **/

#include <string>
#include <iostream>

using namespace std;

static const enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };

class Card
{
public:
    Card(const int, const Suit);
    
    // getter for value
    int getValue() const { return value; }
    
    // setter for value
    void setValue(const int val);
    
    // getter for suit
    Suit getSuit() const { return suit; }

    // setter for suit
    void setSuit(const Suit s);

    // associate the output overload for Card object to grant access
    // to private data member
    friend ostream &operator<<(ostream &out, const Card &c);

private:
    int value;
    Suit suit;
};
