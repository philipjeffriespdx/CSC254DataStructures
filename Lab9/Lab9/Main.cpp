#include <iostream>
#include "sort.h"
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

int myrandom(int i) { return std::rand() % i; }

int main()
{
	srand(unsigned(time(0)));
	
	int num;
	cout << "How many values would you like to sort? (Larger numbers will produce clearer results. Numbers that are too large will take too long to solve.) ";
	cin >> num;
	cout << "Num is: " << num << endl;

	vector<int> nums;
	vector<int> numsWorst;
	vector<int> numsShuffle;

	for (int i = 0; i < num; i++)
	{
		nums.push_back(i);
		
	}
	/*
	for (int i = 0; i < num; i++)
	{
		cout << "" << nums[i] << endl;
	}
	*/
	for (int i = num - 1; i >= 0; i--)
	{
		numsWorst.push_back(i);
	}
	/*
	for (int i = 0; i < num; i++)
	{
		cout << "" << numsWorst[i] << endl;
	}
	*/
	numsShuffle = nums;

	random_shuffle(numsShuffle.begin(), numsShuffle.end(), myrandom);

	// ------------------------------------------------------------------ Best Case --------------------------------------

	cout << "Results for best case: " << endl;
	// insertion sort insertionSort(vector)
	clock_t start1, end1;
	start1 = clock();
	insertionSort(nums);
	end1 = clock();
	cout << "Time insertion sort: " << (end1 - start1) / (double)(CLOCKS_PER_SEC) << endl;


	// shell sort shellsort(vector)
	clock_t start2, end2;
	start2 = clock();
	shellsort(nums);
	end2 = clock();
	cout << "Time shell sort: " << (end2 - start2) / (double)(CLOCKS_PER_SEC) << endl;


	// merge sort mergeSort(vector)
	clock_t start3, end3;
	start3 = clock();
	mergeSort(nums);
	end3 = clock();
	cout << "Time merge sort: " << (end3 - start3) / (double)(CLOCKS_PER_SEC) << endl;

	// ------------------------------------------------------------------ Worst Case --------------------------------------

	cout << "Results for worst case: " << endl;
	// insertion sort insertionSort(vector)
	start1 = clock();
	insertionSort(numsWorst);
	end1 = clock();
	cout << "Time insertion sort: " << (end1 - start1) / (double)(CLOCKS_PER_SEC) << endl;


	// shell sort shellsort(vector)
	start2 = clock();
	shellsort(numsWorst);
	end2 = clock();
	cout << "Time shell sort: " << (end2 - start2) / (double)(CLOCKS_PER_SEC) << endl;


	// merge sort mergeSort(vector)
	start3 = clock();
	mergeSort(numsWorst);
	end3 = clock();
	cout << "Time merge sort: " << (end3 - start3) / (double)(CLOCKS_PER_SEC) << endl;


	// ------------------------------------------------------------------ Random Case --------------------------------------

	cout << "Results for random case: " << endl;
	// insertion sort insertionSort(vector)
	start1 = clock();
	insertionSort(numsShuffle);
	end1 = clock();
	cout << "Time insertion sort: " << (end1 - start1) / (double)(CLOCKS_PER_SEC) << endl;


	// shell sort shellsort(vector)
	start2 = clock();
	shellsort(numsShuffle);
	end2 = clock();
	cout << "Time shell sort: " << (end2 - start2) / (double)(CLOCKS_PER_SEC) << endl;


	// merge sort mergeSort(vector)
	start3 = clock();
	mergeSort(numsShuffle);
	end3 = clock();
	cout << "Time merge sort: " << (end3 - start3) / (double)(CLOCKS_PER_SEC) << endl;
}
