/*
 * @Author: ronin0322
 * @Date: 2022-08-09 01:20:06
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-09 01:20:06
 * @FilePath: /leetcode/sort_list_148/solution.go
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */

package sortlist148

type ListNode struct {
	Val  int
	Next *ListNode
}

func sortList(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	if head.Next == nil {
		return head
	}
	fast, slow := head, head
	pre := head
	for fast != nil && fast.Next != nil {
		fast = fast.Next.Next
		pre = slow
		slow = slow.Next
	}
	pre.Next = nil
	left := sortList(head)
	right := sortList(slow)
	return merge(left, right)
}
func merge(left *ListNode, right *ListNode) *ListNode {
	head := &ListNode{}
	root := head
	for left != nil && right != nil {
		if left.Val < right.Val {
			head.Next = left
			left = left.Next
		} else {
			head.Next = right
			right = right.Next
		}
		head = head.Next
	}
	if left != nil {
		head.Next = left
	}
	if right != nil {
		head.Next = right
	}
	return root.Next
}
