/** Project 2a Deck.h
  * Jie Chen * Patrick Maguire
  * 
  * This file contains the interface for the Deck class
  * 
  **/

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
