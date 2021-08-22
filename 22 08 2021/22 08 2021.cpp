// 22 08 2021.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

template<typename T>
void printContainer(T theContainer, bool addNewLine=true)
{
    for (auto it = theContainer.begin(); it != theContainer.end(); ++it) {
        if ((it + 1) != theContainer.end())
            std::cout << *it << ':';
        else
            std::cout << *it;
    }
    if (addNewLine) std::cout << std::endl;
}

int flatlandSpaceStations(int n, std::vector<int> c) {

    if (c.size() == n) return 0;

    std::unordered_map<int, int> distanceToNearestSpaceStation;
    for (auto spaceStation : c) {
        for (auto city = 0; city < n; ++city) {
            if (distanceToNearestSpaceStation.find(city) == distanceToNearestSpaceStation.end())
                distanceToNearestSpaceStation[city] = abs(city - spaceStation);
            else
                distanceToNearestSpaceStation[city] = std::min(distanceToNearestSpaceStation[city], abs(city - spaceStation));
        }
    }
     
    int maxDistance = 0;
    for (auto& city : distanceToNearestSpaceStation) {
        maxDistance = std::max(city.second, maxDistance);
    }

    return maxDistance;
}


std::string CommonPrefix(const std::string& _stringOne, const std::string& _stringTwo) {
    if (_stringOne.empty() || _stringTwo.empty()) return std::string();
    if (_stringOne == _stringTwo) return _stringOne;

    std::string commonPrefix;
    auto stringOneIter = _stringOne.begin();
    auto stringTwoIter = _stringTwo.begin();

    for (; stringOneIter != _stringOne.end() && stringTwoIter != _stringTwo.end();++stringOneIter,++stringTwoIter) {
        if (*stringOneIter == *stringTwoIter)
            commonPrefix += *stringOneIter;
        else {
            break;
        }
    }

    return commonPrefix;
}

std::string longestCommonPrefix(std::vector<std::string>& strs) {
    
    if (strs.size() == 1) return strs.front();
    if (strs.size() == 2) return CommonPrefix(strs.at(0), strs.at(1));

    auto stringOne = strs.begin();
    auto stringTwo = strs.begin();
    ++stringTwo;

    auto longestCommonPrefix = CommonPrefix(*stringOne, *stringTwo);
    for (; stringOne != strs.end() && stringTwo != strs.end(); ++stringOne, ++stringTwo) {
        longestCommonPrefix = CommonPrefix(longestCommonPrefix, *stringTwo);
        if (longestCommonPrefix.empty()) return std::string();
    }    
    
    return longestCommonPrefix;
}

int main()
{
    {
        std::vector<std::string> strs = { "flower", "flow", "flight" };
        printContainer(strs, false);
        std::cout << " : " << longestCommonPrefix(strs) << std::endl;

    }
    {
        std::vector<std::string> strs = { "dog", "racecar", "car" };
        printContainer(strs, false);
        std::cout << " : " << longestCommonPrefix(strs) << std::endl;
    }
    {
        std::vector<std::string> strs = { "cir", "car" };
        printContainer(strs, false);
        std::cout << " : " << longestCommonPrefix(strs) << std::endl;
    } 

#ifdef flatlandspace
    {
        int n = 6;
        std::vector<int> spaceStations{ 0,1,2,3, 4,5 };
        printContainer(spaceStations, false);
        std::cout << " : " << flatlandSpaceStations(n, spaceStations) << "\n";
    }

    {
        int n = 5;
        std::vector<int> spaceStations {0, 4};
        printContainer(spaceStations, false);
        std::cout << " : " << flatlandSpaceStations(n,spaceStations) << "\n";
    }
#endif // flatlandspace

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
