#include "d_node.h"
#include "Card.h"

class Deck
{
public:
    Deck();
	friend ostream &operator<<(ostream &out, const Deck &d);

private:
    node<Card>* cards;
};
