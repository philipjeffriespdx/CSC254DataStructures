#pragma once
#include <iostream>
#include <queue>
//#include "card.h"
using namespace std;

class card_deck
{
private:

public:
	// constructors
	card_deck();
	card_deck(const string & s);

	//variables
	int size = 0;
	
	//queue
	queue<int> Cards;

	void shuffle();
	void add_card(int num);
	bool is_empty() const;
	int draw();
	void printContents();

};

ostream & operator<<(ostream & out, card_deck & h);
