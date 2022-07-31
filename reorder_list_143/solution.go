/*
 * @Author: ronin0322
 * @Date: 2022-07-31 15:33:43
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-07-31 15:33:44
 * @FilePath: /leetcode/reorder_list_143/solution.go
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */

package reorderlist143

type ListNode struct {
	Val  int
	Next *ListNode
}

func reorderList(head *ListNode) {
	tail := head
	fast := head.Next
	if fast == nil {
		return
	}
	for fast != nil && fast.Next != nil {
		fast = fast.Next.Next
		tail = tail.Next
	}
	nxt := tail.Next
	tail.Next = nil
	tail = reverse(nxt)
	merge(head, tail)
}
func reverse(head *ListNode) *ListNode {
	root := &ListNode{0, head}
	for head.Next != nil {
		nxt := head.Next
		head.Next = nxt.Next
		nxt.Next = root.Next
		root.Next = nxt
	}
	return root.Next
}
func merge(head, tail *ListNode) {
	for head != nil && tail != nil {
		nxtHead, nxtTail := head.Next, tail.Next
		head.Next = tail
		tail.Next = nxtHead
		head, tail = nxtHead, nxtTail
	}
}
