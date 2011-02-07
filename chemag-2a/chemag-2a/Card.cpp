#include "Card.h"

Card::Card(int val, SUIT s) : value(val), suit(s)
{}

ostream &operator<<(ostream &out, const Card &c)
{
	return out << c.getValue() << " of " << STR_SUIT[c.getSuit()];
}
