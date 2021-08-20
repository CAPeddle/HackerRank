// JumpingOnClouds.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup



#include <iostream>
#include <vector>

int jumpingCloudsHelper(std::vector<int>& c, size_t index) {
    //look before you leap
    if (index + 1 >= c.size()) return 0;

    if (index + 1 < c.size() && index + 2 < c.size() &&
        c.at(index + 1) != 1 && c.at(index + 2) != 1) {
        return 1 + std::min(jumpingCloudsHelper(c, index + 1), jumpingCloudsHelper(c, index + 2));
    }
    if (c.at(index + 1) != 1) {
        return 1 + jumpingCloudsHelper(c, index + 1);
    }
    return 1 + jumpingCloudsHelper(c, index + 2);
}

int jumpingOnClouds(std::vector<int> c) {

    if (c.size() == 2 || c.size() == 3) return 1;

    if (c.at(1) != 1 && c.at(2) != 1) {
        return 1 + std::min(jumpingCloudsHelper(c, 1), jumpingCloudsHelper(c, 2));
    }
    if (c.at(1) != 1) {
        return 1 + jumpingCloudsHelper(c, 1);
    }
    return 1 + jumpingCloudsHelper(c, 2);
}

int main()
{
    {
        std::vector<int> input{ 0, 1, 0 };
        std::cout << jumpingOnClouds(input) << "\n";
    }

    {
        std::vector<int> input{ 0, 0, 0, 1, 0, 0 };
        std::cout << jumpingOnClouds(input) << "\n";
    }

    {
        std::vector<int> input{ 0, 0, 1, 0, 0, 1, 0 };
        std::cout << jumpingOnClouds(input) << "\n";
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
