// LongestSubstrWORpeat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

static const auto speedup = []() {ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int bestResult = 0;
		int runStart = 0;
		map<char, int> chars;
		for (int i = 0; i < s.length(); ++i) {
			map<char, int>::iterator it = chars.find(s[i]);
			if (it == chars.end()) {
				chars.insert({ s[i], i });
			}
			else {
				bestResult = getBest(chars.size(), bestResult);
				// Remove conflicting character and all characters preceding it.
				// New run starts from where the first insatnce of conflicting character was + 1.
				int newRunStart = it->second + 1;
				for (int j = it->second; j >= runStart; --j) {
					chars.erase(s[j]);
				}
				runStart = newRunStart;
				chars.insert({ s[i], i });
			}
		}
		bestResult = getBest(chars.size(), bestResult);
		return bestResult;
	}
private:
	int getBest(int currResult, int bestResult) {
		return currResult > bestResult ? currResult : bestResult;
	}
};

/*
" " -> " " (1)
"abcdefcxyzqrsw" -> defcxyzqrsw (11)
"dvdf" -> vdf (3)
"abcabcbb" -> abc (3)
"abcdazxysx" -> bcdazxys (8)
"abcdbzxysx" -> cdbzxys (7)
"tmmzuxt" -> mzuxt (5)
"bbtablud" -> tablud (6)
*/

void print(int i) {
	cout << i << '\n';
}

int main()
{
	Solution solve;

	print(solve.lengthOfLongestSubstring(" "));
	print(solve.lengthOfLongestSubstring("abcdefcxyzqrsw"));
	print(solve.lengthOfLongestSubstring("dvdf"));
	print(solve.lengthOfLongestSubstring("abcabcbb"));
	print(solve.lengthOfLongestSubstring("abcdazxysx"));
	print(solve.lengthOfLongestSubstring("abcdbzxysx"));
	print(solve.lengthOfLongestSubstring("tmmzuxt"));
	print(solve.lengthOfLongestSubstring("bbtablud"));

	/*
	*/
	cin.get();
	return 0;
}

