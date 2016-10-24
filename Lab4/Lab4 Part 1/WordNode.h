#pragma once
#include <iostream>
using namespace std;

// class definition of a WordNode which will be the building block of a WordNodeList
class WordNode
{
public:
	// constructor
	WordNode(string theElement, WordNode * n = NULL)
		: element(theElement), next(n) { }

private:
	WordNode *next;
	string element;

friend class WordNodeList;
};