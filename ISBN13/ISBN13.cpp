// ISBN13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cctype>
#include <array>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <vector>

class ISBN13
{
	static constexpr size_t ISBN_LENGTH = 13;
	//https://en.m.wikipedia.org/wiki/International_Standard_Book_Number#Check_digits
public:
	ISBN13() = default;
		
	bool SetBase(std::string twelve_digits); 	
	std::string GetComplete();

	static std::string Complete(std::string twelve_digits)
	{
		std::unique_ptr<ISBN13> p = std::make_unique<ISBN13>();
		if (p->SetBase(twelve_digits)) {
			return p->GetComplete();
		} else {
			return std::string();
		}
	}

private:
	std::string _digits;
	std::vector<uint8_t> _isbn;

	uint8_t GetCrc(uint8_t sum_of_three) noexcept
	{
		auto modulus = sum_of_three % 10;
		auto ten_and_modulus = 10 - modulus;
		return ten_and_modulus != 10 ? ten_and_modulus : 0;
	}

	std::vector<uint8_t> GetVector()
	{
		_isbn.resize(ISBN_LENGTH);
		
		char digit;
		for (size_t i = 0; i < (ISBN_LENGTH - 1); ++i) {
			digit = _digits[i];
			const auto temp = static_cast<uint8_t>(std::strtoul(&digit, nullptr, 10));
			_isbn[i] = temp;			
		}
		return _isbn;
	}

	uint8_t GetSumByThree(std::vector<uint8_t> isbn)
	{
		if (isbn.empty()) return 0;

		if (isbn.size() % 2 != 0)
		{
			auto current_last = isbn.back();
			isbn.pop_back();
			return current_last + GetSumByThree(isbn);
		}
		else
		{
			auto current_last = isbn.back();
			isbn.pop_back();
			return current_last * 3 + GetSumByThree(isbn);
		}
	}

	std::string GetISBN13()
	{	
		return std::accumulate(std::next(_isbn.begin()), _isbn.end(),
			std::to_string(_isbn[0]),
			[](std::string a, uint8_t b) {
				return std::move(a) + std::to_string(b);
			});
	}
};

bool ISBN13::SetBase(std::string digits)
{
	if (digits.length() != (ISBN_LENGTH-1)) return false;

	for (const auto& digit : digits)
	{
		if (!isdigit(digit)) return false;
	}
		
	_digits = digits;

	return true;
}

std::string ISBN13::GetComplete()
{
	auto twelve_digit = GetVector();
	int sum = GetSumByThree(_isbn);
	int check_digit = GetCrc(sum);
	_isbn[ISBN_LENGTH - 1] = check_digit;
	return GetISBN13();
}

uint8_t get_crc(uint8_t sum_of_three)
{
	auto modulus = sum_of_three % 10;
	auto ten_and_modulus = 10 - modulus;
	return ten_and_modulus != 10 ? ten_and_modulus : 0;
}

uint8_t sum_by_three(std::vector<uint8_t> &isbn)
{
	if (isbn.empty()) return 0;
	
	if (isbn.size() % 2 != 0)
	{
		auto current_last = isbn.back();
		isbn.pop_back();
		return current_last + sum_by_three(isbn);
	}
	else
	{
		auto current_last = isbn.back();
		isbn.pop_back();
		return current_last * 3 + sum_by_three(isbn);
	}
}

std::vector<uint8_t> GetISBN(const std::string &digits)
{
	std::vector<uint8_t> isbn (digits.length(), 0);
		
	if (digits.length() < 12) return isbn;
	
	char digit;
	for (size_t i = 0; i < 12; ++i) {
		digit = digits[i];
		if (isdigit(digits[i]))
		{
			const auto temp = static_cast<uint8_t>(std::strtoul(&digit, nullptr, 10));
			isbn[i] = temp;
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
	std::cout << "Enter 12 digits\n";
	std::string digits;

#define TEST
#ifndef TEST	
	std::getline(std::cin, digits);
#else
	digits = "978014300723";
	//digits = "1234567890123";
#endif

	for (size_t i = 0; i < 3; i++)
	{
		auto isbn = GetISBN(digits);
		int sum = sum_by_three(isbn);
		int check_digit = get_crc(sum);
		
		std::cout << '\n';
		for (const auto& s : isbn)
			std::cout << std::to_string(s) << ' ';

		std::cout << '\n' << sum << '\n' << check_digit;
	}

	std::cout << '\n' << "Class impelementation";
	ISBN13 testisbnclass;
	if (testisbnclass.SetBase(digits)) {
		std::cout << '\n' << testisbnclass.GetComplete();
	}
	else
	{
		std::cout << '\n' << "Fail on digits";
	}
	
	std::cout << '\n' << "Static impelementation";
		
	std::cout << '\n' << ISBN13::Complete(digits);
	
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
