/** Project 2a Deck.h
  * Jie Chen * Patrick Maguire
  * 
  * This file contains the interface for the Deck class
  * 
  * declare the public default constructor for the Deck class 
  * declare the private data member cards 
  *
  **/

#include "d_node.h"
#include "Card.h"

class Deck
{
public:
    Deck();
    // associate the output overload for Deck object to grant access
    // to private data member
    friend ostream &operator<<(ostream &out, const Deck &d);

private:
    node<Card>* cards;
};
