#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "WordNode.h"

// WordNodeList class definition
class WordNodeList
{
private:
	// WordNode pointers
	WordNode *front;
	WordNode *back;
	WordNode *temp;
	WordNode *temp1;
	WordNode *temp2;

	// Variables
	int size = 0;

public:
	// constructors
	WordNodeList();
	WordNodeList(const WordNodeList & rhs);

	//methods
	bool isEmpty() const;
	int numWords();
	void addWord(string word);
	bool findWord(string word);
	void printContents();
	void removeWord(string word);
	void sort(WordNodeList & w);
};

// overloaded outstream operatior for WordNodeList - non-member function
ostream & operator<<(ostream & out, WordNodeList & w);