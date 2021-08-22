// FormingMagicSquare.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://en.wikipedia.org/wiki/Magic_square#Transformations%20that%20preserve%20the%20magic%20property
// 
//

#include <iostream>

template <size_t rows, size_t cols>
int PrintMatrix(int(&array)[rows][cols])
{
    int cost{ 0 };
    std::cout << __func__ << std::endl;
    for (size_t i = 0; i < rows; ++i)
    {
        std::cout << i << ": ";
        for (size_t j = 0; j < cols; ++j)
            std::cout << array[i][j] << '\t';
        std::cout << std::endl;
    }
    return cost;
}


int main()
{
    {
        int x[3][3] = { {5, 3, 4}, {1, 5, 8}, {6, 4, 2} };
        std::cout << PrintMatrix(x) << "\n";
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
