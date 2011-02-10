/** Project 2b program.cpp
  * Jie Chen * Patrick Maguire
  * 
  * This file is the entry point for the project. Defines the main function
  * to run the program for testing.
  * 
  **/

#include <iostream>
#include "d_except.h"
#include "Deck.h"

using namespace std;

int main()
// entry point for the program, handles exceptions thrown during execution
{
    try
    {
       // playFlip();
        Deck d = Deck();
	    cout << d << endl;
        d.shuffle();
        cout << d;
    }
    catch (rangeError &re)
    {
        cout << re.what() << endl;
    }
}
/*
void playFlip()
{
    Deck flipDeck = Deck();
    cout << "Shuffling deck 3 times" << endl;
    flipDeck.shuffle();
    flipDeck.shuffle();
    flipDeck.shuffle();

    string input;
    int score = 0;
    while (input == " ")
    {
        cout << "Your score is: " << score << endl;
        cout << "Press Space to Flip a Card, enter anything else to exit:";
        cin >> input;
        Card c = flipDeck.deal();
        int value = c.getValue();
        Suit s = c.getSuit();
        if (value == 14) 
        {
            score += 10;
        }
        else if (value > 10)
        {
            score += 5;
        }
        else if (value > 7)
        {
            score += 0;
        }
        else if (value == 7)
        {
            score /= 2;
        }
        else if (value < 7)
        {
            score = 0;
        }

        if (s == Suit.HEARTS)
        {
            score++;
        }
    }

}
*/