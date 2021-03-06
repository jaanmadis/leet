// UnivaluedBinaryTree.cpp : Defines the entry point for the console application.
//
// The number of nodes in the given tree will be in the range[1, 100].
// Each node's value will be an integer in the range [0, 99].

#include "stdafx.h"
#include <iostream>

using namespace std;

static const auto speedup = []() {ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	bool checkPreOrder(TreeNode* node, int mustBeVal) {
		if (node != NULL) {
			if (node->val != mustBeVal) {
				return false;
			}
			if (checkPreOrder(node->left, mustBeVal) == false) {
				return false;
			}
			if (checkPreOrder(node->right, mustBeVal) == false) {
				return false;
			}
			return true;
		}
		else {
			return true;
		}
	}
public:
	bool isUnivalTree(TreeNode* root) {
		if (root != NULL) {
			return checkPreOrder(root, root->val);
		}
		else {
			return true;
		}
	}
};

int main()
{
	Solution sol;
	cout << sol.isUnivalTree(NULL);
	cin.get();
	return 0;
}

