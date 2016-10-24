#pragma once
#include <iostream>
using namespace std;

// class definition of card_deck
class card
{
public:
	card(int theElement, card * n = NULL)
		: element(theElement), next(n) {}

private:
	card *next;
	int element;

	friend class card_deck;
};