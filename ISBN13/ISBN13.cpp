// ISBN13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cctype>
#include <array>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <vector>

/*
auto sum_by_three = [](uint8_t a, uint8_t b) {
	static bool applyThree = false;

	if (applyThree)
	{
		applyThree = false;
		return  a + 3 * b;
	}
	else
	{
		applyThree = true;
	}
	
	return a + b;
};
*/
uint8_t sum_by_three(std::vector<uint8_t> &isbn)
{
	if (isbn.empty()) return 0;
	
	if (isbn.size() % 2 == 0) 
		
		return sum_by_three
	return  0;
}

std::vector<uint8_t> GetISBN(const std::string digits)
{
	std::vector<uint8_t> isbn;
	isbn.reserve(digits.length());
	
	auto it = isbn.begin();
	char digit;
	for (size_t i = 0; i < 12; ++i) {
		digit = digits[i];
		if (isdigit(digits[i]))
		{
			const auto temp = static_cast<uint8_t>(std::strtoul(&digit, nullptr, 10));
			isbn.insert(it++,temp);
		}
		else
		{
			std::cout << "Error with input " << digit << "\n";
			return isbn;
		}
	}	
	return isbn;
}

int main()
{
	std::array<uint8_t, 13> isbn = { 0 };
  std::cout << "Enter 12 digits\n";

#ifdef TEST	
	std::getline(std::cin, digits);
#else
	std::string digits = "978014300723";
#endif

	for (size_t i = 0; i < 3; i++)
	{
		isbn = GetISBN(digits);

		int sum = std::accumulate(isbn.begin(), isbn.end(), 0);
		
		auto s = std::accumulate(isbn.begin(), isbn.end(),
			0, // start with first element
			sum_by_three);
			
		std::cout << '\n';
		for (const auto& s : isbn)
			std::cout << std::to_string(s) << ' ';

		std::cout << '\n' << s << '\n' << sum;
	}
	
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
