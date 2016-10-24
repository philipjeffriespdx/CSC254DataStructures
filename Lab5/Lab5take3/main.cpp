#include <iostream>
#include "card_deck.h"
#include <random>
#include <fstream>
#include <assert.h>
using namespace std;

//its_war
void its_war(card_deck & hand1, card_deck & hand2, int card1, int card2)
{
	// hand 1
	int war1, war2, war3;
	// hand 2
	int war4, war5, war6;

	// if the hand is less than three then the players will only put down the number of cards they have
	if (hand1.Cards.size() > 2 && hand2.Cards.size() > 2)
	{
		// lay down two more cards

		// hand 1 cards
		war1 = hand1.Cards.front();
		hand1.Cards.pop();
		war2 = hand1.Cards.front();
		hand1.Cards.pop();
		war3 = hand1.Cards.front();
		hand1.Cards.pop();

		// hand 2 cards
		war4 = hand2.Cards.front();
		hand2.Cards.pop();
		war5 = hand2.Cards.front();
		hand2.Cards.pop();
		war6 = hand2.Cards.front();
		hand2.Cards.pop();

		// third card determines winner
		// winner gets all 8 cards
		if (war3 < war6)
		{
			std::cout << "player 2 wins --->" << endl;
			hand2.add_card(war1);
			hand2.add_card(war2);
			hand2.add_card(war3);
			hand2.add_card(war4);
			hand2.add_card(war5);
			hand2.add_card(war6);
		}
		else if (war3 > war6)
		{
			cout << "player 1 wins --->" << endl;
			hand1.add_card(war1);
			hand1.add_card(war2);
			hand1.add_card(war3);
			hand1.add_card(war4);
			hand1.add_card(war5);
			hand1.add_card(war6);
		}
		// if another tie then there is another war
		else
		{
			cout << war3 << "  " << war6 << " **WAR**" << endl;
			its_war(hand1, hand2, war3, war6);
		}

	}

	// one hand only has two cards left
	else if (hand1.Cards.size() == 2 || hand2.Cards.size() == 2)
	{
		// lay down two more cards

		// hand 1 cards
		war2 = hand1.Cards.front();
		hand1.Cards.pop();
		war3 = hand1.Cards.front();
		hand1.Cards.pop();

		// hand 2 cards
		war5 = hand2.Cards.front();
		hand2.Cards.pop();
		war6 = hand2.Cards.front();
		hand2.Cards.pop();

		// third card determines winner
		// winner gets all 8 cards
		if (war3 < war6)
		{
			std::cout << "player 2 wins --->" << endl;
			hand2.add_card(war2);
			hand2.add_card(war3);
			hand2.add_card(war5);
			hand2.add_card(war6);
			hand2.add_card(card1);
			hand2.add_card(card2);
		}
		else if (war3 > war6)
		{
			cout << "player 1 wins --->" << endl;
			hand1.add_card(war2);
			hand1.add_card(war3);
			hand1.add_card(war5);
			hand1.add_card(war6);
			hand1.add_card(card1);
			hand1.add_card(card2);
		}
		// if another tie then there is another war
		else
		{
			cout << war3 << "  " << war6 << " **WAR**" << endl;
			its_war(hand1, hand2, war3, war6);
		}

	}
	else if (hand1.size == 1 || hand2.size == 1)
	{
		// lay down two more cards

		// hand 1 cards
		war3 = hand1.Cards.front();
		hand1.Cards.pop();

		// hand 2 cards
		war6 = hand2.Cards.front();
		hand2.Cards.pop();

		// third card determines winner
		// winner gets all 8 cards
		if (war3 < war6)
		{
			std::cout << "player 2 wins --->" << endl;
			hand2.add_card(war3);
			hand2.add_card(war6);
			hand2.add_card(card1);
			hand2.add_card(card2);
		}
		else if (war3 > war6)
		{
			cout << "player 1 wins --->" << endl;
			hand1.add_card(war3);
			hand1.add_card(war6);
			hand1.add_card(card1);
			hand1.add_card(card2);
		}
		// if another tie then there is another war
		else
		{
			cout << war3 << "  " << war6 << " **WAR**" << endl;
			its_war(hand1, hand2, war3, war6);
		}
	}
	// if player has no cards he looses war
	else if (hand1.size == 0)
	{
		cout << "Player 2 wins by default." << endl;
	}
	else if (hand2.size == 0)
	{
		cout << "Player 1 wins by default." << endl;
	}

	cout << "\nHand 1 is:";
	hand1.printContents();
	cout << "\nHand 2 is:";
	hand2.printContents();
	cout << endl;
}

// play method
void play(card_deck & hand1, card_deck & hand2)
{
	char response = 'N';
	while (response == 'N' && (!hand1.is_empty() || !hand1.is_empty()))
	{
		if (hand1.Cards.front() < hand2.Cards.front())
		{
			std::cout << "player 2 wins --->" << endl;
			hand2.add_card(hand1.Cards.front());
			hand1.Cards.pop();
			hand1.size--;
			hand2.size++;
		}
		else if (hand1.Cards.front() > hand2.Cards.front())
		{
			cout << "player 1 wins --->" << endl;
			hand1.add_card(hand2.Cards.front());
			hand2.Cards.pop();
			hand2.size--;
			hand1.size++;
		}
		else
		{
			cout << hand1.Cards.front() << "  " << hand2.Cards.front() << " **WAR**" << endl;
			its_war(hand1, hand2, hand1.Cards.front(), hand2.Cards.front());
		}

		cout << "\nHand 1 is:";
		hand1.printContents();
		cout << "\nHand 2 is:";
		hand2.printContents();
		cout << "\nHit N to see next round" << endl;
		cin >> response;
	}
}

int main()
{
	card_deck hand1;
	card_deck hand2;

	card_deck deck("\\\\vmware-host\\Shared Folders\\Documents\\simple_cards.txt");


	deck.shuffle();
	cout << "After shuffle, the deck looks like this " << endl << endl;
	cout << deck << endl;

	cout << "Hit D to deal" << endl;
	char play_it;
	cin >> play_it;


	while (!deck.is_empty())
	{

		hand1.add_card(deck.draw());
		hand2.add_card(deck.draw());
	}
	cout << "Hand 1 is :" << hand1 << endl;
	cout << "Hand 2 is :" << hand2 << endl;

	cout << "Ready to play?" << endl;
	cin >> play_it;
	if (play_it == 'y' || play_it == 'Y')
	{
		play(hand1, hand2);

		if (hand1.is_empty())
		{
			cout << "Player 2 wins !!" << endl;
		}
		else if (hand2.is_empty())
		{
			cout << "Player 1 wins !!" << endl;
		}
	}
	else
		cout << "Game aborted" << endl;

	return 0;
}






//

// its_war function

// 
