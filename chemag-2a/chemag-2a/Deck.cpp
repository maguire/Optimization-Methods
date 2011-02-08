#include "Deck.h"

Deck::Deck()
{
    node<Card>* prev = NULL;
    for (int j = 3; j >= 0; j--)
    {
        for (int i = 14; i >= 2; i--)
        {
            // create a new node in a linked list that contains
            // a Card which the second argument ordinal must be cast to a SUIT
            // enum
            cards = new node<Card>(Card(i, (SUIT)j), prev);
            prev = cards;
        }
    }
}

ostream &operator<<(ostream &out, const Deck &d)
{
    node<Card>* card = d.cards;
    while (card != NULL)
    {
        out << card->nodeValue <<  endl;
        card = card->next;

    }
    return out;
}
