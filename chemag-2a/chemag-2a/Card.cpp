#include "Card.h"

Card::Card(int val, string s) : value(val), suit(s)
{}

ostream &operator<<(ostream &out, const Card &c)
{
    out << c.value << " of " << c.suit;
}
