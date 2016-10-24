#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

template <class InputIterator, class T>
T accumulate(InputIterator first, InputIterator last, T init)
{
	double temp = 0;
	while (first != last) 
	{
		temp = temp + *first;  // or: init=binary_op(init,*first) for the binary_op version
		++first;
	}
	return temp/init;
}

int main()
{
	map<string, double> students;

	vector<double> stud;

	bool Continue = true;
	bool Retry = true;
	int Choice;
	char c;
	string ws;
	char tempCr;
	double dTemp1;
	double dTemp2;
	string sTemp1;
	string sTemp2;

	cout << "Please choose from the following options" << endl;
	cout << "1. Add a student" << endl;
	cout << "2. Remove a student" << endl;
	cout << "3. Print thte grade for a particular student" << endl;
	cout << "4. Replace a grade for a particular student" << endl;
	cout << "5. Print all of student names and grades" << endl;
	cout << "6. Print the average of the current grades" << endl;
	cout << "7. quit" << endl;

	while (Continue)
	{

		while (Retry)
		{
			cout << "Next operation:  ";
			//cin >> ws;
			c = cin.peek();
			//cout << "Value of char c is: " << c << endl;
			if (((c - '0') >= 0) && ((c - '0') <= 7))  //e.g., invalid character input 
			{
				cin >> Choice;
				cin.ignore();
				Retry = false;
			}
			else
			{
				cin >> ws;
				cin.ignore();
				cout << "Please enter a number between 1 and 7 \n\n";
				//cin.ignore(256, '\n');

			}
		}
		Retry = true;

		switch (Choice)
		{
		case 1: // Add a student
			cout << "Enter the last name and grade separated by a space:  ";
			cin >> sTemp1 >> dTemp1;
			//cout << sTemp1 << endl;
			//cin.ignore(1, ' ');
			//cin >> dTemp1;
			//cout << dTemp1 << endl;
			students[sTemp1] = dTemp1;
			cout << endl;
			cin.ignore();
			break;
		case 2: // Remove a student
			cout << "What is the last name of the student you wish to remove?  ";
			cin >> sTemp1;
			students.erase(sTemp1);
			cout << endl;
			cin.ignore();
			break;
		case 3: // Print the grade for a particular student
			cout << "Whose grade would you like to print?  ";
			cin >> sTemp1;
			cout << sTemp1 << " " << students[sTemp1] << '\n';
			cin.ignore();
			break;
		case 4: // Replace a grade for a particual student
			cout << "Whose grade needs to be replaced?  ";
			cin >> sTemp1;
			cout << "New grade?  ";
			cin >> dTemp1;
			students[sTemp1] = dTemp1;
			cin.ignore();
			break;
		case 5: // Print all of student names and grades
			for (map<string, double>::iterator it = students.begin(); it != students.end(); ++it)
			{
				cout << it->first << " " << it->second << '\n';
			}
			cout << endl;
			break;
		case 6: // Print the average of the current grades
			for (map<string, double>::iterator it = students.begin(); it != students.end(); ++it)
			{
				stud.push_back(it->second);
			}
			dTemp2 = accumulate(stud.begin(), stud.end(), stud.size());
			stud.clear();
			cout << "The average is: " << setprecision(5) << dTemp2 << "\n" << endl;

			break;
		case 7: // quit
			cout << "good-bye" << endl;
			exit(0);
			break;
		}

	}

	return 0;
}