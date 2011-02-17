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
#include "d_except.h"
#include "d_random.h"
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
    node<Card>* next = NULL;
    while (cards != NULL)
    {
        next = cards->next;
	delete cards;
	cards = next;
    }
}

Card Deck::deal()
//deal the next card off the top
{
    if( cards != NULL )
    {
	node<Card>* c = cards;
	Card headCard = c->nodeValue;
	cards = cards->next;
	delete c;
	return headCard;
    }
    else 
    {
	throw underflowError("You cannot deal from an empty deck");
    }
}

void Deck::replace(Card c)
// put a given card at the bottom of the deck, ie the bottom of the linkedlist
{
    node<Card>* crd;
    node<Card>* lastCard;

    crd = cards;
    int count = 0;
    // loop through the list to get to the last node
    while(crd != NULL)
    {
	if (crd->next == NULL)
	{
	    lastCard = crd; // save the last node
	}
        crd = crd->next;
	count++;
    }

    // if we tried to insert over 52 cards throw an error
    if ( count > 51 )
    {
	throw overflowError("You can't add more cards to a full deck!");
    }
		
    // link new card with bottom of the deck
    crd = new node<Card>(c, NULL);
    lastCard->next = crd;
}

void Deck::shuffle()
// shuffle the cards by converting to a vector and then calling random_shuffle
// in the algorithms class and then updating all the cards in the linkedlist
{
    vector<Card> shuffledCards;
    node<Card>* card = cards;
    // convert the linkedList to a vector
    while(card != NULL)
    {
        shuffledCards.push_back(card->nodeValue);
        card = card->next;
    }
	
    // shuffle the vector of cards
    randomNumber genRandNum;
    for (int i = shuffledCards.size()-1; i > 0; i--)
    {
	int j = genRandNum.random(i);
	Card tmp = shuffledCards[i];
	shuffledCards[i] = shuffledCards[j];
	shuffledCards[j] = tmp;	
    }

    // convert vector back to linkedList
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
