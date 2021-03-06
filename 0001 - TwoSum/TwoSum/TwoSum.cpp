/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return[0, 1].
*/

#include "stdafx.h"
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> twoSumBrute(vector<int>& nums, int target) {
		for (int it1 = 0; it1 < nums.size(); ++it1) {
			for (int it2 = it1 + 1; it2 < nums.size(); ++it2) {
				if (nums.at(it2) == target - nums.at(it1)) {
					return { it1, it2 };
				}
			}
		}
	}
	vector<int> twoSumIterators(vector<int>& nums, int target) {
		for (vector<int>::iterator it1 = nums.begin(); it1 != nums.end(); ++it1) {
			for (vector<int>::iterator it2 = it1 + 1; it2 != nums.end(); ++it2) {
				if (*it2 == target - *it1) {
					return { distance(nums.begin(), it1), distance(nums.begin(), it2) };
				}
			}
		}
	}
	vector<int> twoSumMap(vector<int>& nums, int target) {
		map<int, int> numMap = { { nums.at(0), 0 } };
		for (vector<int>::iterator it = nums.begin() + 1; it != nums.end(); ++it) {
			map<int, int>::iterator found = numMap.find(target - *it);
			if (found != numMap.end()) {
				return { found->second, distance(nums.begin(), it) };
			}
			else {
				numMap.insert({ *it, distance(nums.begin(), it) });
			}
		}
	}
};

void print(vector<int>& nums) {
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
		cout << *it;
	}
}

int main()
{
	vector<int> nums{ 10, 11, 12, 13, 14, 15, 16, 17, 3, 2, 4 };
	int target = 6;
	Solution solution;
	vector<int> solutions;

	solutions = solution.twoSumBrute(nums, target);
	print(solutions);

	solutions = solution.twoSumIterators(nums, target);
	print(solutions);

	solutions = solution.twoSumMap(nums, target);
	print(solutions);

	cin.get();
	return 0;
}

