/** Project 2a Deck.cpp
  * Jie Chen * Patrick Maguire
  * 
  * This file contains the implementation for the Deck class
  * 
  * Define the Deck default constructor
  * 
  * Define the global function that overloads the '<<' operator for the Deck
  * class
  * 
  **/

#include "Deck.h"

Deck::Deck()
// the Deck default constructor that creates a deck in the following order:
// all Clubs 2 -> Ace, then Hearts, then Diamonds and Spades.
// design: the link list used to represent a deck is created backwards
{
    node<Card>* prev = NULL;
    for (int j = 3; j >= 0; j--)
    {
        for (int i = 14; i >= 2; i--)
        {
            // create a new node in a linked list that contains
            // a Card which the second argument ordinal must be cast to a Suit
            // enum
            cards = new node<Card>(Card(i, static_cast<Suit>(j)), prev);
            prev = cards;
        }
    }
}

ostream &operator<<(ostream &out, const Deck &d)
// overload output stream operator for Deck object
{
    node<Card>* card = d.cards;
    while (card != NULL)
    {
        out << card->nodeValue <<  endl;
        card = card->next;
    }
    return out;
}
