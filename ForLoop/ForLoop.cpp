// ForLoop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <sstream>

using namespace std;

//https://stackoverflow.com/questions/20594520/what-exactly-does-stringstream-do/44782764
int main() {
	// Complete the code.
	int numberOne, numberTwo;
	cin >> numberOne;
	cin >> numberTwo;

	for (int i = numberOne; i <= numberTwo; ++i)
	{
		switch (i)
		{
			case 1:
				cout << "one\n";
			break;
			case 2:
				cout << "two\n";
				break;
			case 3:
				cout << "three\n";
				break;
			case 4:
				cout << "four\n";
				break;
			case 5:
				cout << "five\n";
				break;
			case 6:
				cout << "six\n";
				break;
			case 7:
				cout << "seven\n";
				break;
			case 8:
				cout << "eight\n";
				break;
			case 9:
				cout << "nine\n";
				break;
			default:
				if (i > 9 && i % 2 != 0) cout << "odd\n";
				if (i > 9 && i % 2 == 0) cout << "even\n";
			break;
		}
		
	}
	
	cin.get();

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
