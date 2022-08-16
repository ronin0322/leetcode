/*
 * @Author: ronin0322
 * @Date: 2022-08-16 09:14:04
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-16 09:14:19
 * @FilePath: /leetcode/add_two_numbers_2/solution.cpp
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		int sum = 0;
		ListNode *head = new ListNode();
		ListNode *root = head;
		for (; l1 || l2;)
		{
			head->next = new ListNode();
			head = head->next;
			int l1v = 0, l2v = 0;
			if (l1)
			{
				l1v = l1->val;
				l1 = l1->next;
			}
			if (l2)
			{
				l2v = l2->val;
				l2 = l2->next;
			}
			sum = sum + l1v + l2v;
			head->val = sum % 10;
			sum = sum / 10;
		}
		if (sum > 0)
		{
			head->next = new ListNode();
			head = head->next;
			head->val = sum;
		}
		return root->next;
	}
};