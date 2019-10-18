// VariableSizedArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <iterator>

std::vector<int> GetVariableArray(const std::string inputString)
{
	const char* p = inputString.data();
	char *end;
	std::vector<int> v;
	
	for (long i = std::strtol(p, &end, 10);
		p != end;
		i = std::strtol(p, &end, 10))
	{
		p = end;
		if (errno == ERANGE) {
			errno = 0;			
		} else
		{
			v.push_back(i);
		}
	}
	return v;
}

std::vector<int> GetArray()
{
	int l;
	std::cin >> l;
	std::vector<int> v;
	int val;
	
	for (int i = 0; i < l; ++i)
	{
		std::cin >> val;
		v.push_back(val);
	}

	return v;
}

std::pair<int, int> GetQuery()
{
	int n, q;

	std::cin >> n >> q;

	return std::make_pair(n, q);
}

int main()
{
	const auto nAndQ = GetQuery();
	std::vector<std::vector<int>> variableArray;

	//std::string arrayString;
	//for (auto i = 0; i < nAndQ.first; ++i)
	//{
	//	std::getline(std::cin, arrayString);
	//	variableArray.push_back(GetVariableArray(arrayString));
	//}

	for (auto i = 0; i < nAndQ.first; ++i)
	{
		variableArray.push_back(GetArray());
	}
	
	std::vector<std::pair<int, int>> queries;
	for (auto i = 0; i < nAndQ.second; ++i)
	{
		queries.push_back(GetQuery());
	}

	for (auto i = 0; i < nAndQ.second; ++i)
	{
		const auto arrayIndex = queries.at(i).first;
		const auto valInArray = queries.at(i).second;
		std::cout << variableArray.at(arrayIndex).at(valInArray) << "\n";
	}
}
