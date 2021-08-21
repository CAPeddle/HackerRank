// MakingAnagrams.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.hackerrank.com/challenges/ctci-making-anagrams
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

std::string remove_letter(std::string str, char c)
{
    for (auto iter = str.begin(); iter != str.end(); )
    {
        if (*iter == c) iter = str.erase(iter);
        else ++iter;
    }
    return str;
}

int number_needed(std::string a, std::string b) {
    auto count = 0;
    std::vector<int> freq(26, 0);
    for (auto c : a) { ++freq[c - 'a']; }
    for (auto c : b) { --freq[c - 'a']; }
    for (auto val : freq) { count += abs(val); }
    return count;
}

int makeAnagram(std::string a, std::string b) {

    size_t erases = 0;


   
    return erases;
}

int main()
{
    {
        std::string a{ "fcrxzwscanmligyxyvym" };
        std::string b{ "jxwtrhvujlmrpdoqbisbwhmgpmeoke" };

        std::cout << a << "|" << b << " :" << number_needed(a,b) << "\n";
    }

    {
        std::string a{ "cde" };
        std::string b{ "abc" };

        std::cout << a << "|" << b << " :" << makeAnagram(a,b) << "\n";
    }

    {
        std::string a{ "cde" };
        std::string b{ "dcf" };

        std::cout << a << "|" << b << " :" << makeAnagram(a, b) << "\n";
    }

    {
        std::string a{ "cde" };
        std::string b{ "abc" };

        std::cout << a << "|" << b << " :" << makeAnagram(a, b) << "\n";
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
