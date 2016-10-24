/*#include <iostream>
#include "BinarySearchTree.h"
#include "AvlTree.h"
#include <vector>
using namespace std;

int main()
{

	BinarySearchTree<int> MyBST;
	AvlTree<int> MyAVL;

	for (int i = 1; i < 11; i++)
	{
		MyBST.insert(i);
		MyAVL.insert(i);
	}

	cout << "Height of BST is " << MyBST.getHeight() << endl;
	cout << "Operations required for BST " << MyBST.getOP() << endl;
	cout << "Height of AVL is " << MyAVL.getHeight() << endl;
	cout << "Operations required for AVL " << MyAVL.getOP() << endl;


	//MyBST.printTree();


	//MyAVL.printTree();


	MyBST.makeEmpty();
	MyAVL.makeEmpty();

	vector<int> MyVector = { 5,4,7,2,3,9,6 };

	for (int i = 0; i < MyVector.size(); i++)
	{
		MyBST.insert(MyVector[i]);
		MyAVL.insert(MyVector[i]);
	}

	cout << "Height of BST is " << MyBST.getHeight() << endl;
	cout << "Operations required for BST " << MyBST.getOP() << endl;
	cout << "Height of AVL is " << MyAVL.getHeight() << endl;
	cout << "Operations required for AVL " << MyAVL.getOP() << endl;

	//MyBST.printTree();


	//MyAVL.printTree();



}
*/
