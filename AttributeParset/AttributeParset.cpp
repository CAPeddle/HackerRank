// AttributeParset.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> GetHRML(int q)
{
	std::vector<std::string> _hrml;
	std::string str;
	
	while (q--)
	{
		getline(std::cin, str);
		_hrml.push_back(str);
	}

	return _hrml;
}


std::pair<int, int> GetQuery()
{
	int n, q;

	std::cin >> n >> q;

	return std::make_pair(n, q);
}

int main()
{
    std::cout << "Enter N & Q\n";

		auto nAndq = GetQuery();

		std::cout << "Enter HRML\n";
		auto hrml = GetHRML(nAndq.second);

    std::cout << "nAndq " << nAndq.first << ":" << nAndq.second << std::endl;
    for (auto const & oneLine : hrml)
    {
			std::cout << oneLine;
    }

    std::cout << "\nhit a key" << std::endl;
    std::cin.get();
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
