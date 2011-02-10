/** Project 2a Card.h
  * Jie Chen * Patrick Maguire 
  *
  * This file contains the interface for the Card class
  * 
  * It declares the public constructor, the getter and setters for the data 
  * members.
  * 
  * It declares the private data members value and suit
  * 
  * It contains data structure used for translations of values that 
  * correspond to the royal values in a deck of cards
  *
  **/

#include <string>
#include <iostream>

using namespace std;

enum SUIT { CLUBS, HEARTS, DIAMONDS, SPADES };

static string STR_SUIT[] = { "Clubs", "Hearts", "Diamonds", "Spades" };

static string royalValue[] = { "Jack", "Queen", "King" , "Ace" };

class Card
{
public:
    Card(int, SUIT);
    
    // getter for value
    int getValue() const { return value; }
    
    // setter for value
    void setValue(int val);
    
    // getter for suit
    SUIT getSuit() const { return suit; }

    // setter for suit
    void setSuit(SUIT s);
    
    // associate the output overload for Card object to grant access
    // to private data member
    friend ostream &operator<<(ostream &out, const Card &c);

private:
    int value;
    SUIT suit;
};
