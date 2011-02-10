/** Project 2b Deck.cpp
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
#include <vector>
#include <algorithm>
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
            cards = new node<Card>(Card(i, (Suit)j), prev);
            prev = cards;
        }
    }
}

Deck::~Deck()
//destructor for the Deck class deletes first node
// which subsequently deletes each node 
{
    //TODO: write this 
}

Card Deck::deal()
//deal the next card off the top
{
    Card headCard = cards->nodeValue;
    cards = cards->next;
    return headCard;
}

void Deck::replace(Card c)
{
    node<Card>* card = cards;
    while(card != NULL)
    {
        card = card->next;
    }
    card->next = new node<Card>(c, NULL);
}

void Deck::shuffle()
// shuffle the cards by converting to a vector and then calling random_shuffle
// in the algorithms class and then updating all the cards in the linkedlist
{
    vector<Card> shuffledCards;
    node<Card>* card = cards;
    while(card != NULL)
    {
        shuffledCards.push_back(card->nodeValue);
        card = card->next;
    }

    random_shuffle(shuffledCards.begin(), shuffledCards.end());
    
    int i = 0;
    node<Card>* head;
    head = cards;
    while(cards != NULL)
    {
        cards->nodeValue = shuffledCards[i];
        cards = cards->next;
        i++;
    }
    cards = head;
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
