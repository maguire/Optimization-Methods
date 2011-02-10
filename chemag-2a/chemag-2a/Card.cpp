/** Project 2a Card.cpp
  * Jie Chen * Patrick Maguire
  * 
  * This file contains the implementation for the Card class.
  *
  * It defines the constructor, setValue, setSuit, and a gobal function
  * that overloads the output operator for the Card class
  *
  * It contains data structure used for translations of values that 
  * correspond to the royal values in a deck of cards
  **/

#include "Card.h"
#include "d_except.h"

static const string str_suit[] = { "Clubs", "Diamonds", "Hearts", "Spades" };

static const string royalValue[] = { "Jack", "Queen", "King" , "Ace" };

Card::Card(const int val, const Suit s)
// simple Card constructor
{
    setValue(val);
    setSuit(s);
}

void Card::setValue(const int val)
// setter for Card value, does bound checking
// throws rangeError when out of bound parameter is passed
{
    if (val <= 14 && val >= 2)
    {
        value = val;
    }
    else
    {
        throw rangeError("Card value must be in the range [2,14]");
    }
}

void Card::setSuit(const Suit s)
// setter for the Card Suit, does bound checking
// throws rangeError if given an invalid suit enum
{
    if (s < 0 || s > 3)
    {
        string msg = "The suit given is invalid, must be one of: ";
        msg += "CLUBS, DIAMONDS, HEARTS, or SPADES";
	    throw rangeError(msg);
    }

    suit = s;
}

ostream &operator<<(ostream &out, const Card &c)
// overload '<<' operator for Card object
{
    int cardValue = c.getValue();

    if (cardValue < 11)
    {
        out << cardValue << " of " << str_suit[c.getSuit()];
    }
    else
    {
        out << royalValue[cardValue - 11] << " of " << str_suit[c.getSuit()];
    }

    return out;
}// End operator<<()
