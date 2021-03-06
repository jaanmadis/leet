/*
Given a string s, find the longest palindromic substring in s. 
You may assume that the maximum length of s is 1000.

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb"
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

static const auto speedup = []() {ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution {
public:
	string longestPalindrome(string s) {
		string se = addPadding(s);
		vector<int> P(se.length(), 0);
		int maxPos = -1;
		for (unsigned i = 0; i < se.length(); ++i) {
			P[i] = getPalindromeLength(se, i);
			if (maxPos == -1 || P[maxPos] < P[i]) {
				maxPos = i;
			}
		}
		return getPalindrome(se, maxPos);
	}
private:
	string addPadding(string s) {
		string result = "#";
		for (unsigned i = 0; i < s.length(); ++i) {
			result = result + s[i] + "#";
		}
		return result;
	}
	int getPalindromeLength(string s, int center) {
		int left = center - 1;
		int right = center + 1;
		int result = 0;
		while (0 <= left && right < s.length()) {
			if (s[left] == s[right]) {
				--left;
				++right;
				++result;
			}
			else {
				break;
			}
		}
		return result;
	}
	string getPalindrome(string s, int center) {
		string result = "";
		int left;
		int right;
		if (s[center] == '#') {
			left = center - 1;
			right = center + 1;
		}
		else {
			result = s[center];
			left = center - 2;
			right = center + 2;
		}
		while (0 <= left && right < s.length()) {
			if (s[left] == s[right]) {
				result = s[left] + result + s[right];
				left = left - 2;
				right = right + 2;
			}
			else {
				break;
			}
		}
		return result;
	}
};

class SolutionBrute {
public:
	string longestPalindrome(string s) {
		int bestHead = 0;
		int bestTail = 0;
		for (int head = 0; head < s.length(); ++head) {
			for (int tail = s.length() - 1; head < tail; --tail) {
				if (bestTail - bestHead >= tail - head) {
					break;
				}
				if (s[head] == s[tail]) {
					bool valid = true;
					for (int left = head + 1, right = tail - 1; left < right; ++left, --right) {
						if (s[left] != s[right]) {
							valid = false;
							break;
						}
					}
					if (valid) {
						bestHead = head;
						bestTail = tail;
					}
				}
			}
		}
		string result = "";
		for (int i = bestHead; i <= bestTail; ++i) {
			result = result + s[i];
		}
		return result;
	}
};

void test1() {
	Solution sol;
	cout << sol.longestPalindrome("cbbd") << '\n';
	cout << sol.longestPalindrome("a") << '\n';
	cout << sol.longestPalindrome("ac") << '\n';
	cout << sol.longestPalindrome("abcda") << '\n';
	cout << sol.longestPalindrome("cbbd") << '\n';
	cout << sol.longestPalindrome("6amelema123456kuulilennuteetunneliluukKANASITT") << '\n';
	cout << sol.longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << '\n';
}

int main()
{
	test1();
	cin.get();
	return 0;
}

