#include <iostream>
#include <string>
using namespace std;
#include "WordNodeList.h"

// Default constructor of WordNodeList
WordNodeList::WordNodeList() : front(NULL), back(NULL), size(0)
{}

// Overloaded constructor of WordNodeList
WordNodeList::WordNodeList(const WordNodeList & rhs)
	: front(NULL), back(NULL), size(0)
{
	*this = rhs;
}

// Will return true if the WordNodeList is empty
bool WordNodeList::isEmpty() const
{
	return front == NULL;
}

// Returns the size of the WordNodeList
int WordNodeList::numWords()
{
	return size;
}

// Uses pointers front and back which are private members of WordNodeList.h to add a new WordNode to the list
void WordNodeList::addWord(string word)
{
	if (isEmpty())
		back = front = new WordNode(word);
	else
		back = back->next = new WordNode(word);

	size++;
}

// Searches through a list for a word which the user passes in
bool WordNodeList::findWord(string word)
{
	temp = front;
	// Chck if list is empty
	if (isEmpty())
	{
		cout << "its empty" << endl;
		return false;
	}
	// if list is not empty loop through it in search for the word
	for (int i = 0; i < size; i++)
	{
		if (temp->element == word)
		{
			return true;
		}
		else { 
			temp = temp->next; 
		}
	}
	return false;
}

// Removes a word from the list that the user passes in
void WordNodeList::removeWord(string word)
{
	temp1 = front;
	
	bool go = true;
	// If the list is empty then it will produce an err message
	if (isEmpty())
	{
		cerr << "List is empty." << endl;
	}
	else if (front->element == word) 
	{
		// If the word that needs to be removed is the first word then that could produce an error in the future if we do not also change the pointer "front"
		temp1 = temp1 -> next;
		front = front->next;
		size--;
	}
	else // Otherwise we continue as normal and loop through the entire list looking for the word
	{
		for (int i = 1; i < size; i++)
		{
			if (temp1->next->element == word)
			{
				temp2 = temp1->next;
				temp1->next = temp2->next;
				size--;
			}
			else
			{
				temp1 = temp1->next;
			}
		}
	}
}

// Prints elements in the list
void WordNodeList::printContents()
{
	// we need newFront because we do not want to change the location which front points to
	WordNode *newFront = front;
	for (int i = 0; i < size; i++)
	{ 
		if (newFront != NULL)
		{
			cout << newFront->element << endl;
		}
		newFront = newFront->next;
	}
}

// Sorts the elements in the list by creating a second list
void WordNodeList::sort( WordNodeList & w)
{
	// Second list s
	WordNodeList s;
	int sizer = w.size;
	// This for loop loops through all the elements in list w
	for (int j = 0; j < sizer; j++)
	{
		temp1 = front;
		temp2 = front;
		// This loop searches for the highest alphabetical element in w and adds it to the next spot in s
		for (int i = 0; i < w.size; i++)
		{	
			if (temp1->element > temp2->element)
			{
				temp1 = temp2;
			}
			temp2 = temp2->next;
		}
		s.addWord(temp1->element);
		w.removeWord(temp1->element);
	}
	// After everything has been added in the correct order to s and removed from w we set w equal to s
	w = s;
}

// Overloading the outstream opperator
ostream & operator<<(ostream & out, WordNodeList & w)
{
	w.printContents();
	return out;
}