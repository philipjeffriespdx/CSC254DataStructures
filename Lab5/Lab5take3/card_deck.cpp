#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <fstream>
#include "card_deck.h"
using namespace std;

// default constructor
card_deck::card_deck() {}

card_deck::card_deck(const string & s)
{
	string tempS;
	int tempNum;

	// write instructions for reading in a file
	ifstream myfile(s);

	//std::cout << "\nFile name is " << s << endl;

	if (myfile.is_open())
	{
		while (getline(myfile, tempS))
		{
			tempNum = stoi(tempS);
			add_card(tempNum);
		}
		myfile.close();
	}
	else 
		std::cout << "\nUnable to open file";

}

bool card_deck::is_empty() const
{
	return Cards.empty();
}

void card_deck::add_card(int num)
{
	Cards.push(num);
	size++;
}

template <class RandomAccessIterator, class RandomNumberGenerator>
void random_shuffle(RandomAccessIterator first, RandomAccessIterator last,
	RandomNumberGenerator& gen)
{
	iterator_traits<RandomAccessIterator>::difference_type i, n;
	n = (last - first);
	for (i = n - 1; i>0; --i) {
		swap(first[i], first[gen]);
	}
}

void card_deck::shuffle()
{
	vector<int> nums;

	int counter = 1;
	for (int i = 0; i < Cards.size(); i++)
	{
		//cout << counter << " is : " << Cards.pop() << endl;
		nums.push_back(Cards.front());
		Cards.pop();
	}
	int num = 0;
	for (int i = 0; i <  nums.size(); i++)
	{
		num = i;
		random_shuffle(nums.begin(), nums.end(), num);
	}
	for (int i = 0; i < nums.size(); i++)
	{
		Cards.push(nums[i]);
	}
}

int card_deck::draw()
{
	if (!Cards.empty())
	{
		int temp = Cards.front();
		Cards.pop();
		return temp;
	}
	else
		return 0;
}

void card_deck::printContents()
{
	int temp;
	for (int i = 0; i < Cards.size(); i++)
	{
		std::cout << Cards.front();
		temp = Cards.front();
		Cards.pop();
		Cards.push(temp);
	}
}


ostream & operator<<(ostream & out, card_deck & h)
{
	h.printContents();
	return out;
}


