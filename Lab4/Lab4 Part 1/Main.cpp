#include <iostream>
#include "WordNodeList.h"
#include <string>
using namespace std;

int main()
{
	// Create instance of WordNodeList
	WordNodeList w;

	// Instantiate main variables
	bool Continue = true;
	int Choice = 1;
	int temp = 0;
	bool temp2;
	string temp3;

	// User Options
	cout << "Please choose from the following operations <Enter 6 to quit>" << endl;
	cout << "1. Add a word to the end of of the list:" << endl;
	cout << "2. Remove a word from the list:" << endl;
	cout << "3. Print the list: " << endl;
	cout << "4. Sort the list: " << endl;
	cout << "5. Search for a word in the list: " << endl;

	// Main loop which continues only if user enters a number 1-5
	while (Continue)
	{
		cin >> Choice;
		
		// Switch statment chooses which operation depending on what the user input is
		switch (Choice)
		{
		case 1: // Adds a word to the end
			cout << "Enter word: ";
			cin >> temp3;
			// Call to addWord method
			w.addWord(temp3);
			break;
		case 2: // Removes a word which user indicates
			cout << "Word to remove: ";
			cin >> temp3;
			// Call to removeWord method
			w.removeWord(temp3);
			break;
		case 3: // Prints contents in WordNodeList, << is overloaded in WordNodeList.cpp
			cout << w << endl;
			break;
		case 4: // Sorts the contents in WordNodeList
			// Call to sort method
			w.sort(w);
			cout << "You selected sort contents: " << endl;
			w.printContents();
			break;
		case 5: // Word search in list
			cout << "Word to search for: " << endl;
			cin >> temp3;
			// Call to findWord method
			if (w.findWord(temp3))
			{
				cout << temp3 << " was found." << endl;
			}
			else
			{
				cout << temp3 << " was not found." << endl;
			}
			break;
		default: // If user enters number other than 1-5
			cout << "Good - bye" << endl;
			Continue = false;
		}

		cout << "\nNext operation? ";
	}

	return 0;
}
