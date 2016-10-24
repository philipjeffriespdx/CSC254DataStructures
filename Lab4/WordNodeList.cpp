#include <iostream>
#include <string>
using namespace std;
#include "WordNodeList.h"


WordNodeList::WordNodeList() : front(NULL), back(NULL), size(0)
{}

WordNodeList::WordNodeList(const WordNodeList & rhs)
	: front(NULL), back(NULL), size(0)
{
	*this = rhs;
}

bool WordNodeList::isEmpty() const
{
	return front == NULL;
}

int WordNodeList::numWords()
{
	return size;
}

void WordNodeList::addWord(string word)
{
	if (isEmpty())
		back = front = new WordNode(word);
	else
		back = back->next = new WordNode(word);

	size++;
}

bool WordNodeList::findWord(string word)
{
	temp = front;

	if (isEmpty())
	{
		cout << "its empty" << endl;
		return false;
	}

	for (int i = 0; i < size; i++)
	{
		if (temp->element == word)
		{
			return true;
		}
		else { 
			cout << "nope" << endl;
			temp = temp->next; 
		}
	}
	return false;
}

void WordNodeList::removeWord(string word)
{
	temp1 = front;
	
	bool go = true;
	if (isEmpty())
	{
		cerr << "List is empty." << endl;
	}
	else if (front->element == word)
	{
		temp1 = temp1 -> next;
		front = front->next;
		size--;
	}
	else 
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
void WordNodeList::printContents()
{
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

void WordNodeList::sort(const WordNodeList)
{
	//create new list
	WordNode *tempNode = front;
	WordNode *tempNode2 = front;

	WordNodeList s;
	//take elements alphabetically from old to new
	
	
	
	for (int i = 0; i < size; i++)
	{
		tempNode2 = tempNode2->next;
		if (tempNode->element < tempNode2->element)
		{

		}
		if ('a' < 'b')
		{
		}

	}

	//rewrite elements to old list

	//free memory of temporary list
}



ostream & operator<<(ostream & out, WordNodeList & w)
{
	w.printContents();
	return out;
}