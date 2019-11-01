// AttributeParset.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <utility>
#include <vector>
#include <string>

class Attribute
{
	
public:
	Attribute()
	= default;

	~Attribute() {  }
	
	void SetName(std::string p_name) { m_name = std::move(p_name); }
	std::string Name() const { return m_name; }
	
private:
	std::string m_name;
	std::vector< std::pair<std::string, std::string > > m_attributes;

	std::vector< std::unique_ptr<Attribute> > m_subTags;
};

std::vector<std::string> GetLines(int q)
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
	std::cin.ignore(1000, '\n');

	return std::make_pair(n, q);
}

int main()
{
    std::cout << "Enter N & Q\n";

		auto nAndq = GetQuery();

		std::cout << "Enter HRML " << nAndq.first << "\n";
		auto hrml = GetLines(nAndq.first);

		std::cout << "Enter Queries " << nAndq.second << "\n";
		auto queries = GetLines(nAndq.second);
	
    std::cout << "nAndq " << nAndq.first << ":" << nAndq.second << std::endl;
    for (auto const & oneLine : hrml)
    {
			std::cout << oneLine << "\n";
    }

		std::cout << "Queries " << std::endl;
		for (auto const& oneLine : queries)
		{
			std::cout << oneLine << "\n";
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
