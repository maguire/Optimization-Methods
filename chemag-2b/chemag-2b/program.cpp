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

void playFlip()
{
    Deck flipDeck = Deck();
    cout << "Shuffling deck 3 times" << endl;
    flipDeck.shuffle();
    flipDeck.shuffle();
    flipDeck.shuffle();

    int score = 0;
	cout << "Your score is: " << score << endl;
    cout << "Press Enter to Flip a Card, enter anything else to exit:";

	int count = 0;
    while (cin.get() == '\n')
	{

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

        if (s == HEARTS)
        {
            score++;
        }
		count++;

		if (count == 52) 
		{
			cout << "You have played through the entire deck. " << endl;
			break;
		}

		cout << "You got a " << c << ". Your score is: " << score << endl;
        cout << "Press Enter to Flip a Card, enter anything else to exit:";
		flipDeck.replace(c);
		
    }

}

int main()
// entry point for the program, handles exceptions thrown during execution
{
    try
    {
        playFlip();
    }
    catch (rangeError &re)
    {
        cout << re.what() << endl;
    }
	catch (underflowError &ue)
	{
		cout << ue.what() << endl;
	}
	catch (overflowError &oe)
	{
		cout << oe.what() << endl;
	}

}

