#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <list>
using namespace std;

// Function declarations
int hashThis(int key, int tablesize);
void iLinProb(const vector<int> & a, vector<int> & b);
void iQuadProb(const vector<int> & a, vector<int> & b);
void iChain(const vector<int> & a, vector<list<int>> & b);

int main()
{
	// Vector of ints
	vector<int> nums;
	string line = "";

	// Read values from file, # of items must be less than table size
	ifstream file("\\\\vmware-host\\Shared Folders\\Documents\\HashNums.txt");

	int temp = 0;
	if (file.is_open())
	{
		while ( getline(file,line))
		{
			int temp = atoi(line.c_str());
			nums.push_back(temp);
		}
	}

	// Table size is determined by user imput
	int numHash = 0;
	cout << "What size do you want your hash to be? ";
	cin >> numHash;

	// create 3 tables, LP, QP, C
	// Linear probing
	vector<int> vlinprob;
	vlinprob.resize(numHash);
	iLinProb(nums, vlinprob);

	vector<int> vquadprob;
	vquadprob.resize(numHash);
	iQuadProb(nums, vquadprob);

	vector<list<int>> vchain;
	vchain.resize(numHash);
	iChain(nums, vchain);


	file.close();

}

// Call this hash funciton by the insert functions
int hashThis(int key, int tablesize)
{
	return key % tablesize;
}

void iLinProb(const vector<int> & a, vector<int> & b)
{
	// a is nums
	// b is vlinprob
	
	// linear probing 
	// attempts to place value in a hashed location
	// if something is already there it puts it in the next location
	// it keeps checking until it finds a spot
	int temp = 0;
	int collisions = 0;

	for (unsigned i = 0; i < a.size(); i++)
	{
		// b.size() is the size of the vchain which is the size of numHash.  They are the same size so I am not going to pass in another #
		// here I am hashing the first value of the nums vector and putting it into temp

		temp = hashThis(a[i], b.size());

		// add temp to b

		// my error is here
		// seeing if the list is empty
		if (b[temp] == NULL)
		{
			// add the value of vector a into the linked list at the hashed location for b
			b[temp] = a[i];
		}
		// check to see if there is already a list
		else
		{
			// loop through table looking for open value
			while (b[temp] != NULL)
			{
				// increment collisions
				collisions++;
				temp++;
			}
			b[temp] = a[i];
		}
	}

	cout << "Number of collisions for linear probing is: " << collisions << endl;
}

void iQuadProb(const vector<int> & a, vector<int> & b)
{
	// a is nums
	// b is vquad prob

	// quadratic probing 
	// attempts to place value in a hashed location
	// if something is already there it puts it in the next location in a series of i, i+1, i-1, i+4, i-4, i+9, i-9... etc.
	// it keeps checking until it finds a spot
	int temp = 0;
	unsigned collisions = 0;
	int quad = 1;
	unsigned counter = 2;
	unsigned newTemp = 0;

	for (unsigned i = 0; i < a.size(); i++)
	{
		// b.size() is the size of the vchain which is the size of numHash.  They are the same size so I am not going to pass in another #
		// here I am hashing the first value of the nums vector and putting it into temp

		temp = hashThis(a[i], b.size());

		// add temp to b

		// my error is here
		// seeing if the list is empty
		if (b[temp] == NULL)
		{
			// add the value of vector a into the linked list at the hashed location for b
			b[temp] = a[i];
		}
		// check to see if there is already a list
		else
		{
			newTemp = temp;
			counter = 2;
			quad = 1;

			// loop through table looking for open value
			while (b[newTemp] != NULL)
			{
				// increment collisions
				collisions++;
				
				// we need to make temp go up and down at a quadratic amount

				// this if statment makes the i + or i - , I am using a counter that either has a remainder of 0 or 1
				if (counter % 2 == 0)
				{
					// remainder is 0 then it is i + , so I am adding the quad squared to i
					newTemp = temp + (quad * quad);

					// if the addition to newTemp made it larger than the size of the vector we wrap it around by subtractin the size of the vector
					while (newTemp > b.size())
					{
						if(newTemp>b.size())
							newTemp = newTemp - b.size();
					}
				}
				else if (counter % 2 == 1)
				{
					// remainder is 1 then it is i - , so I am subtracting the quad squared from i
					newTemp = temp - (quad * quad);
					// after every subtraction the quad is incremented
					quad++;

					// if the subtraction put newTemp less than zero we wrap it around by adding the size of the vector to it
					while (newTemp < 0)
					{
						if (newTemp < 0)
						{
							newTemp = newTemp + b.size();
						}
					}
				}

				// increment counter for know whether to add or subtract 
				counter++;
			}
			// once a value is null then add newTemp to the vector
			b[newTemp] = a[i];
		}
	}
	/*
	for (int i = 0; i < b.size(); i++)
	{
		cout << "Quad prob final vector " << i << ": " << b[i] << endl;
	}
	*/
	cout << "Number of collisions for quadratic probing is: " << collisions << endl;
}

void iChain(const vector<int> & a, vector<list<int>> & b)
{
	int temp = 0;
	unsigned checks = 0;
	bool add = true;
	int * temporary;

	for (unsigned i = 0; i < a.size(); i++)
	{
		// b.size() is the size of the vchain which is the size of numHash.  They are the same size so I am not going to pass in another #
		// here I am hashing the first value of the nums vector and putting it into temp

		// making add true since we assume there are not duplicate values until we find them
		add = true;

		temp = hashThis(a[i], b.size());

		// add temp to b

		// my error is here
		// seeing if the list is empty
		if (b[temp].empty() == true )
		{
			// add the value of vector a into the linked list at the hashed location for b

			b[temp].push_back(a[i]);
		}
		// check to see if there is already a list
		else
		{
			// pointer to the front of the list we are adding to
			temporary = & b[temp].front();


			for (unsigned i = 0; i < b[temp].size(); i++)
			{
				// if value is already in linked list then do not add
				if (*temporary = a[i])
					add = false;
				temporary++;
				checks++;
			}

			// no duplicate values, add to list
			if (add = true)
				b[temp].push_back(a[i]);
		}
	}

	cout << "Number of checks for chaining is: " << checks << endl;
}
