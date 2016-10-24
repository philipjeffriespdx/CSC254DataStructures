#include <iostream>
#include "BinarySearchTree.h"
#include "AvlTree.h"
#include <vector>
#include <list>

//random
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;


//random function
int myrandom(int i) 
{ 
	return std::rand() % i; 
}

int main()
{

	BinarySearchTree<int> MyBST;
	AvlTree<int> MyAVL;

	vector<int> ints;

	double bstHeights = 0;
	double avlHeights = 0;


	for (int j = 0; j < 20; j++)
	{
		for (int i = 0; i < 32; i++)
		{
			ints.push_back(i);
		}

		//srand(unsigned(time(0)));

		random_shuffle(ints.begin(), ints.end(), myrandom);

		for (int i = 0; i < 32; i++)
		{
			MyBST.insert(ints[i]);
			MyAVL.insert(ints[i]);
		}

		cout << "Height of BST is " << MyBST.getHeight() << endl;
		bstHeights += MyBST.getHeight();
		cout << "Operations required for BST " << MyBST.getOP() << endl;
		cout << "Height of AVL is " << MyAVL.getHeight() << endl;
		avlHeights += MyAVL.getHeight();
		cout << "Operations required for AVL " << MyAVL.getOP() << endl;


		MyBST.makeEmpty();
		MyAVL.makeEmpty();

		cout << "\n" << endl;
	}

	
	cout << "Average BST height: " << bstHeights / 20 << endl;
	cout << "Average AVL height: " << avlHeights / 20 << endl;

	
}

