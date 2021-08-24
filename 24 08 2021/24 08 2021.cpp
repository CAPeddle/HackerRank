// 24 08 2021.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <list>


class Solution {
public:
	int findKthLargest(std::vector<int>& nums, int k) {

		m_kth = k;

		for (auto element = nums.begin(); element != nums.end(); ++element) {
			Add(*element);
		}

		return m_minHeap.front();
	}
private:
	int m_kth{ 0 };
	std::list<int> m_minHeap;

	int Add(const int newElement)
	{
		if (m_minHeap.empty()) {
			m_minHeap.push_back(newElement);
			return newElement;
		}

		if (newElement >= m_minHeap.back()) {
			m_minHeap.push_back(newElement);
		}
		else {
			for (auto positionInMinHeap = m_minHeap.begin(); positionInMinHeap != m_minHeap.end(); ++positionInMinHeap) {
				if (newElement < *positionInMinHeap) {
					m_minHeap.insert(positionInMinHeap, newElement);
					break;
				}
			}
		}

		if (m_minHeap.size() > m_kth) {
			m_minHeap.pop_front();
		}

		return m_minHeap.front();
	}	
};

int main()
{
	auto sol = Solution();

	std::vector<int> nums{ 3, 2, 3, 1, 2, 4, 5, 5, 6 };
	int  kth = 4;
    std::cout << sol.findKthLargest(nums, kth) << "\n";

}

/*
https://www.educative.io/blog/google-coding-interview-questions

ie 3rd largest meaning minimum 
Input: [4, 1, 3, 12, 7, 14], K = 3
1. Calling add(6) should return '7'.
2. Calling add(13) should return '12'.
2. Calling add(4) should still return '12'.

4, 1, 3, 12, 7, 14

1,3,4,7,12,14

1,3,4,7,12,14

*/

