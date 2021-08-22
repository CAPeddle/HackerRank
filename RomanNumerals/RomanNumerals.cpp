// RomanNumerals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

std::string GetRomanNumerals(int number) {

    std::string result;

    if (number == 4) return "IV";
    if (number == 9) return "IX";

    if (number > 4 && number < 10) {
        result += "V";
        number -= 5;
    }
    else if (number > 9) {
        result += "X";
        number -= 10;
    }

    while (number --> 0) {
        result += "I";
    }

    return result;
}

int main()
{
    {
        int number = 11;

        while (number --> 1) {
            std::cout << number << ":" << GetRomanNumerals(number) << "\n";

        }
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
