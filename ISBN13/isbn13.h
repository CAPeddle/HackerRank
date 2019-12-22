#pragma once

#include <numeric>
#include <sstream>
#include <vector>
#include <algorithm>

class ISBN13
{
	static constexpr size_t ISBN_LENGTH = 13;
	//https://en.m.wikipedia.org/wiki/International_Standard_Book_Number#Check_digits
public:
	ISBN13() = default;

	bool SetBase(std::string twelve_digits)
	{
		Sanitize(twelve_digits);

		if (twelve_digits.length() != (ISBN_LENGTH - 1)) return false;

		for (const auto& digit : twelve_digits)
		{
			if (!isdigit(digit)) return false;
		}

		_digits = twelve_digits;

		return true;
	}

	std::string GetComplete()
	{
		auto twelve_digit = GetVector();
		int sum = GetSumByThree(_isbn);
		int check_digit = GetCrc(sum);
		_isbn.push_back(check_digit);
		return GetISBN13();
	}

	static std::string Complete(std::string twelve_digits)
	{
		std::unique_ptr<ISBN13> p = std::make_unique<ISBN13>();
		if (p->SetBase(twelve_digits)) {
			return p->GetComplete();
		}
		else {
			return std::string();
		}
	}

	static bool IsValidISBN13(std::string thirteen_digits)
	{
		Sanitize(thirteen_digits);

		if (thirteen_digits.length() != ISBN_LENGTH) return false;

		std::unique_ptr<ISBN13> p = std::make_unique<ISBN13>();
		if (p->SetBase(thirteen_digits.substr(0, (ISBN_LENGTH - 1)))) {
			return p->GetComplete() == thirteen_digits;
		}
		else {
			return false;
		}
	}

	static void Sanitize(std::string& digits)
	{
		digits.erase(std::remove(digits.begin(), digits.end(), '-'), digits.end());
		digits.erase(std::remove(digits.begin(), digits.end(), ' '), digits.end());
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
		_isbn.resize(ISBN_LENGTH - 1);

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

