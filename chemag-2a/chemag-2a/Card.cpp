#include "Card.h"
#include "d_except.h"

Card::Card(int val, SUIT s) 
{
    setValue(val);
    setSuit(s);
}

void Card::setValue(int val)
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
