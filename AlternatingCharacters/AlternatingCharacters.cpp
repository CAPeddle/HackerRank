// AlternatingCharacters.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.hackerrank.com/challenges/alternating-characters
//

#include <iostream>

std::string remove_letter(std::string str, char c)
{
    for (auto iter = str.begin(); iter != str.end(); )
    {
        if (*iter == c) iter = str.erase(iter);
        else ++iter;
    }
    return str;
}

int alternatingCharacters(std::string str) {

    int erases(0);
    for (auto iter = str.begin(); iter != str.end(); )
    {
        if (iter + 1 != str.end()){
            if (*iter == *(iter + 1)) {
                iter = str.erase(iter);
                ++erases;
            }
            else ++iter;
        }
        else {
            ++iter;
        }
    }

    return erases;
}

int main()
{
    {
        std::string s{ "AABAAB" };
        std::cout << s << ":" << alternatingCharacters(s) << "\n";  
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
