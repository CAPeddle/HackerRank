// 23 08 2021.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "..\catch.hpp"

#include <iostream>

std::string CreateRow(int columns, int queenPostion) {
    std::string row;
    for (auto column = 0; column < columns; ++column) {
        if (column == queenPostion) row += "Q";
        else
        {
            row += ".";
        }
    }
    return row;
}

std::vector<std::string> ConvertBoardFormat(std::vector<int> _board) {

    std::vector<std::string> result;
    for (size_t column = 0; column < _board.size(); ++column) {
        std::string rowString;
        for (size_t row = 0; row < _board.size(); ++row) {
            if (row == _board.at(column)) {
                rowString += "Q";
            }
            else {
                rowString +=".";
            }
        }
        result.push_back(rowString);
    }
    return result;
}

void PrintBoard(std::vector<int>& _board) {
    std::cout << " Board " << std::endl;
    for (size_t column = 0; column < _board.size(); ++column) {
        for (size_t row = 0; row < _board.size(); ++row) {
            if (row == _board.at(column)) {
                std::cout << "Q";
            }
            else {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool SolveQueen(std::vector<int>& _board, int size) {
    if (_board.size() > 1) {
        for (size_t i = 0; i < _board.size() - 1; ++i)
        {
            if (_board.at(i) == _board.back()) {
                return false;
            }

            auto boardAtI = _board.at(i);
            auto boardBack = _board.back();
            auto existingNegMC = i - _board.at(i);
            auto newNegMC = (_board.size() - 1) - _board.back();
            if (existingNegMC == newNegMC) {
                return false;
            }

            auto existingPosMC = _board.at(i) + i;
            auto newPosMC = (_board.size() - 1) + _board.back();
            if (existingPosMC == newPosMC) {
                return false;
            }
        }
    }
    
    for (auto queenInRowPosition = 0; queenInRowPosition < size; ++queenInRowPosition) {        
        auto newBoard = _board;
        newBoard.push_back(queenInRowPosition);
        if (SolveQueen(newBoard, size)) {
            _board = newBoard;
            return true;
        }        
    }
    if (_board.size() == size) return true;
    return false;
}

std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector < std::vector<int>> possibleSolutions;
    for (auto queenInRowPosition = 0; queenInRowPosition < n; ++queenInRowPosition) {
        
        std::vector<int> ColumnOneOption{ queenInRowPosition };

        if (SolveQueen(ColumnOneOption, n)) {
            //PrintBoard(ColumnOneOption);
            possibleSolutions.push_back(ColumnOneOption);
        }
    }
    
    std::vector<std::vector<std::string>> result;
    for (auto board : possibleSolutions) {
        result.push_back(ConvertBoardFormat(board));
    }

    return result;
}

int countNumbersWithUniqueDigits(int n) {

        if (n == 0)
            return 1;
        if (n == 1)
            return 10;
        std::vector<int> a(n + 1);
        int k = 8;
        a[0] = 0;
        a[1] = 10;
        a[2] = 91;
        for (int i = 3; i <= n; i++) {
            a[i] = a[i - 1] + (a[i - 1] - a[i - 2]) * k;
            k--;
        }
        return a[n];
    

    //if (n == 0) return 1; n--;

    //int totalUniqueNums = 10;  // 0 & (1, 2, 3 ... 9) for n = 0 & n = 1
    //int uniqueNums = 9;        // (1, 2, 3 ... 9) for n = 1
    //int digitsLeft = 9;        // 9 left since only one digit is used

    //while (n && digitsLeft) {  // because when digitsLeft = 0, we cannot make new numbers 
    //    uniqueNums = uniqueNums * digitsLeft;  // making new numbers 
    //    totalUniqueNums += uniqueNums;   // adding to total result
    //    digitsLeft--; n--;
    //}

    //return totalUniqueNums;
}

TEST_CASE("Count Unique Digits", "LeetCode") {

    REQUIRE(countNumbersWithUniqueDigits(2) == 91);
    REQUIRE(countNumbersWithUniqueDigits(3) == 739);
}

//https://leetcode.com/problems/n-queens/
TEST_CASE("N - Queens Problem", "General") {

    {
        int n = 5;
        std::vector<std::vector<std::string>> solution{ {".Q..", "...Q", "Q...", "..Q."},{"..Q.", "Q...", "...Q", ".Q.."} };
        REQUIRE(solveNQueens(n) == solution);
    }

    {
        int n = 4;
        std::vector<std::vector<std::string>> solution{ {".Q..", "...Q", "Q...", "..Q."},{"..Q.", "Q...", "...Q", ".Q.."} };
        REQUIRE(solveNQueens(n) == solution);
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu[[".Q..", "...Q", "Q...", "..Q."], ["..Q.", "Q...", "...Q", ".Q.."]]

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
