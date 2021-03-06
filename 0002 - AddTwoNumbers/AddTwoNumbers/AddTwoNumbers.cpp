/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, 
except the number 0 itself.

Examples:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

Input: (2 -> 4 -> 3 -> 1) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8 -> 1
Explanation: 1342 + 465 = 1807.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4 -> 1 -> 2)
Output: 7 -> 0 -> 8 -> 1 -> 2
Explanation: 342 + 21465 = 21807.

Input: (0) + (1 -> 2 -> 3)
Output: 1 -> 2 -> 3
Explanation: 0 + 321 = 321.

Input: (5) + (5)
Output: 0 -> 1
Explanation: 5 + 5 = 10.
*/

#include "stdafx.h"
#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	// Overengineering
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int w1 = getWidth(l1);
		int w2 = getWidth(l2);
		if (w1 < 19 && w2 < 19) {
			return addTwoNumbersInt(l1, l2);
		} else {
			return addTwoNumbersLL(l1, l2);
		}
	}

	// This only works for smaller numbers. 
	// Unclear if it is faster than Linked list version.
	// Should be easier to read, though.
	ListNode* addTwoNumbersInt(ListNode* l1, ListNode* l2) {
		ListNode* result = NULL;
		if (l1 != NULL && l2 != NULL) {
			unsigned long long int i1 = getNum(l1);
			unsigned long long int i2 = getNum(l2);
			unsigned long long int sum = i1 + i2;
			int digit;
			ListNode* next = NULL;
			do {
				digit = sum % 10;
				sum = sum / 10;
				ListNode* ln = new ListNode(digit);
				if (result == NULL) {
					result = ln;
					next = result;
				} else {
					next->next = ln;
					next = next->next;
				}
			} while (sum > 0);
		}
		return result;
	}
	
	ListNode* addTwoNumbersLL(ListNode* l1, ListNode* l2) {
		ListNode* result = NULL;
		if (l1 != NULL && l2 != NULL) {
			ListNode* lnpA = l1;
			ListNode* lnpB = l2;
			ListNode lnZero(0);
			ListNode* lnNext = NULL;
			int sum;
			bool carry = false;
			do {
				sum = lnpA->val + lnpB->val + (carry ? 1 : 0);
				if (sum > 9) {
					sum = sum - 10;
					carry = true;
				} else {
					carry = false;
				}
				ListNode* lnDigit = new ListNode(sum);
				if (result == NULL) {
					result = lnDigit;
					lnNext = result;
				} else {
					lnNext->next = lnDigit;
					lnNext = lnNext->next;
				}
				lnpA = lnpA->next;
				lnpB = lnpB->next;
				if (lnpA == NULL) {
					lnpA = &lnZero;
				}
				if (lnpB == NULL) {
					lnpB = &lnZero;
				}
			} while (lnpA != &lnZero || lnpB != &lnZero);
			if (carry) {
				ListNode* lnDigit = new ListNode(1);
				lnNext->next = lnDigit;
			}
		}
		return result;
	}
private:
	unsigned long long int getNum(ListNode* root) {
		ListNode* ln = root;
		unsigned long long int result = 0;
		unsigned long long int ten = 1;
		do {
			result = ln->val * ten + result;
			ten = ten * 10;
			ln = ln->next;
		} while (ln != NULL);
		return result;
	}

	int getWidth(ListNode* root) {
		int result = 0;
		ListNode* ln = root;
		while (ln != NULL) {
			++result;
			ln = ln->next;
		}
		return result;
	}
};

using namespace std;

int main()
{
	/*
	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)

	ListNode lnA1(2);
	ListNode lnA2(4);
	ListNode lnA3(3);

	lnA1.next = &lnA2;
	lnA2.next = &lnA3;

	ListNode lnB1(5);
	ListNode lnB2(6);
	ListNode lnB3(4);

	lnB1.next = &lnB2;
	lnB2.next = &lnB3;

	[9]
	[1,9,9,9,9,9,9,9,9,9]
	[0, 1,8,4,4,6,7,4,4,0,7,3,7,0,9,5,5,1,6,1,5]
	if digits > 19 then
	*/
	ListNode lnA1(9);

	ListNode lnB1(1);
	ListNode lnB2(9);
	ListNode lnB3(9);
	ListNode lnB4(9);
	ListNode lnB5(9);
	ListNode lnB6(9);
	ListNode lnB7(9);
	ListNode lnB8(9);
	ListNode lnB9(9);
	ListNode lnBA(9);

	lnB1.next = &lnB2;
	lnB2.next = &lnB3;
	lnB3.next = &lnB4;
	lnB4.next = &lnB5;
	lnB5.next = &lnB6;
	lnB6.next = &lnB7;
	lnB7.next = &lnB8;
	lnB8.next = &lnB9;
	lnB9.next = &lnBA;

	/*
	Input: (2 -> 4 -> 3 -> 1) + (5 -> 6 -> 4)
	*/

	ListNode lnC1(2);
	ListNode lnC2(4);
	ListNode lnC3(3);
	ListNode lnC4(1);

	lnC1.next = &lnC2;
	lnC2.next = &lnC3;
	lnC3.next = &lnC4;

	ListNode lnD1(5);
	ListNode lnD2(6);
	ListNode lnD3(4);

	lnD1.next = &lnD2;
	lnD2.next = &lnD3;

	/*
	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4 -> 1 -> 2)
	*/

	ListNode lnE1(2);
	ListNode lnE2(4);
	ListNode lnE3(3);

	lnE1.next = &lnE2;
	lnE2.next = &lnE3;

	ListNode lnF1(5);
	ListNode lnF2(6);
	ListNode lnF3(4);
	ListNode lnF4(1);
	ListNode lnF5(2);

	lnF1.next = &lnF2;
	lnF2.next = &lnF3;
	lnF3.next = &lnF4;
	lnF4.next = &lnF5;

	/*
	Input: (0) + (1 -> 2 -> 3)
	*/

	ListNode lnG1(0);

	ListNode lnH1(1);
	ListNode lnH2(2);
	ListNode lnH3(3);

	lnH1.next = &lnH2;
	lnH2.next = &lnH3;

	/*
	Input: (5) + (5)
	*/

	ListNode lnI1(5);
	ListNode lnJ1(5);

	Solution solution;

	ListNode* lns1 = solution.addTwoNumbers(&lnA1, &lnB1);
	ListNode* lns2 = solution.addTwoNumbers(&lnC1, &lnD1);
	ListNode* lns3 = solution.addTwoNumbers(&lnE1, &lnF1);
	ListNode* lns4 = solution.addTwoNumbers(&lnG1, &lnH1);
	ListNode* lns5 = solution.addTwoNumbers(&lnI1, &lnJ1);

	// We're not freeing the linked lists created in addTwoNumbers!

	cin.get();
	return 0;
}

