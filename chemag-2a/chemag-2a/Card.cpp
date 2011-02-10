/** Project 2a Card.cpp
  * Jie Chen * Patrick Maguire
  * 
  * This file contains the implementation for the Card class.
  *
  * It defines the constructor, setValue, setSuit, and a gobal function
  * that overloads the output operator for the Card class
  **/



#include "Card.h"
#include "d_except.h"

Card::Card(int val, SUIT s)
// simple Card constructor
{
    setValue(val);
    setSuit(s);
}

void Card::setValue(int val)
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

void Card::setSuit(SUIT s)
{
    suit = s;
}

ostream &operator<<(ostream &out, const Card &c)
// overload '<<' operator for Card object
{
    int cardValue = c.getValue();

    if (cardValue < 11)
    {
        out << cardValue << " of " << STR_SUIT[c.getSuit()];
    }
    else
    {
        out << royalValue[cardValue - 11] << " of " << STR_SUIT[c.getSuit()];
    }

    return out;
}
