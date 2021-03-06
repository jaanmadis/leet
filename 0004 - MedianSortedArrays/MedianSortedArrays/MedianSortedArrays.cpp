/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).
You may assume nums1 and nums2 cannot be both empty.
*/

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

static const auto speedup = []() {ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int>::iterator it1 = nums1.begin();
		vector<int>::iterator it2 = nums2.begin();
		vector<int> merge;
		do {
			if (it1 == nums1.end() && it2 == nums2.end()) {
				break;
			}
			else if (it1 == nums1.end()) {
				merge.insert(merge.end(), it2, nums2.end());
				break;
			}
			else if (it2 == nums2.end()) {
				merge.insert(merge.end(), it1, nums1.end());
				break;
			}
			else {
				if (*it1 < *it2) {
					merge.push_back(*it1);
					++it1;
				}
				else {
					merge.push_back(*it2);
					++it2;
				}
			}
		} while (true);

		// Even
		if (merge.size() % 2 == 0) {
			return (merge[merge.size() / 2 - 1] + merge[merge.size() / 2]) / (double)2;
		}
		
		// Odd
		else {
			return merge[merge.size() / 2];
		}
	}
};

int main()
{
	Solution sol;
	double ans;

	vector<int> nums1 = { 1, 3 };
	vector<int> nums2 = { 2 };
	ans = sol.findMedianSortedArrays(nums1, nums2);

	vector<int> nums3 = { 1, 2 };
	vector<int> nums4 = { 3, 4 };
	ans = sol.findMedianSortedArrays(nums3, nums4);

	return 0;
}

