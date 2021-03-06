// NumWSameConsecutiveDiff.cpp : Defines the entry point for the console application.
//

/*
Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.
Note that every number in the answer must not have leading zeros except for the number 0 itself. 
For example, 01 has one leading zero and is invalid, but 0 is valid.
You may return the answer in any order.

Input: N = 3, K = 7
Output: [181,292,707,818,929]

Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]

1 <= N <= 9 // length of the number
0 <= K <= 9 // difference between digits 
*/

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

static const auto speedup = []() {ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution {
public:
	vector<int> numsSameConsecDiff(int N, int K) {
		vector<int> result({});
		if (N >= 2) {
			vector<int> tmp({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
			int currLen = 1;
			while (currLen < N) {
				result = addOneDigit(&tmp, K);
				tmp = result;
				++currLen;
			}
		}
		else {
			result.insert(result.end(), { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 });
		}
		return result;
	}
private:
	vector<int> addOneDigit(vector<int>* oldInts, int K) {
		vector<int> result;
		int lastDigit;
		for (vector<int>::iterator it = oldInts->begin(); it != oldInts->end(); ++it) {
			lastDigit = *it % 10;
			if (lastDigit + K < 10) {
				result.push_back(*it * 10 + lastDigit + K);
			}
			if (lastDigit - K >= 0 && K != 0) {
				result.push_back(*it * 10 + lastDigit - K);
			}
		}
		return result;
	}
};

int main()
{
	Solution sol;
	vector<int> ints = sol.numsSameConsecDiff(9, 3);
	for (vector<int>::iterator it = ints.begin(); it != ints.end(); ++it) {
		cout << *it << '\n';
	}
	cout << ints.size() << " numbers";
	cin.get();
	return 0;
}

