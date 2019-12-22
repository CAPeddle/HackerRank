#include <iostream>
#include "isbn13.h"
#include <fstream>
#include <deque>

int main()
{
	std::cout << "Enter 12 digits\n";
	std::string digits;

#define TEST
#ifndef TEST	
	std::getline(std::cin, digits);
#else
	digits = "978014300723";
#endif

	std::cout << "\nClass implementation\n";
	ISBN13 testisbnclass;
	if (testisbnclass.SetBase(digits)) {
		auto output = testisbnclass.GetComplete();
		std::cout << output << " IsValid:" << (ISBN13::IsValidISBN13(output) == true ? "True" : "False") << '\n';
	}
	else
	{
		std::cout << "Fail on digits\n";
	}

	std::cout << "\nStatic implementation\n";
	auto static_output = ISBN13::Complete(digits);
	std::cout << static_output << " IsValid:" << (ISBN13::IsValidISBN13(static_output) == true ? "True" : "False") << '\n';

	std::cout << "\nManual Dirty Quick Test\n";
	std::string line;
	std::ifstream myfile("InValidISBN.txt");
	
	std::deque<std::string> test_data_invalid;
	std::deque<std::string> test_data_valid;

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			test_data_invalid.push_back(line);
#ifdef CONFIRM_TESTDATA
			std::cout << line << "\t IsValid: " << (ISBN13::IsValidISBN13(line) == true ? "True" : "False") << '\n';
#endif
		}
		myfile.close();
	}
	myfile.open("ValidISBN.txt");

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			test_data_valid.push_back(line);
#ifdef CONFIRM_TESTDATA
			std::cout << line << "\t IsValid: " << (ISBN13::IsValidISBN13(line) == true ? "True" : "False") << '\n';
#endif
		}
		myfile.close();
	}

	for (auto& full_isbn : test_data_valid)
	{
		if (testisbnclass.SetBase(full_isbn.substr(0, full_isbn.length()-1))) {
			auto output = testisbnclass.GetComplete();
			std::cout << full_isbn << "\t->\t" << output << " IsValid:" << (ISBN13::IsValidISBN13(output) == true ? "True" : "False") << '\n';
		}
		else
		{
			std::cout << "Fail on digits\n";
		}
	}

	auto output = ISBN13::IsValidISBN13(line);

}