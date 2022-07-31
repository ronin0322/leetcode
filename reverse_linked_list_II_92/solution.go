package reverse_linked_list_ii92

/*
 * @Author: ronin0322
 * @Date: 2022-07-30 22:50:43
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-07-30 23:03:56
 * @FilePath: /go-leetcode/reverse_linked_list_II_92/solution.go
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseBetween(head *ListNode, left int, right int) *ListNode {
	root := &ListNode{0, head}
	findNode := func(limit int) *ListNode {
		idx := 0
		curNode := root
		for idx < limit {
			curNode = curNode.Next
			idx++
		}
		return curNode
	}
	leftNode := findNode(left - 1)
	rightNode := findNode(right)
	nxt := leftNode.Next
	leftNode.Next = nil
	tail := rightNode.Next
	rightNode.Next = nil
	leftNode.Next = reverse(nxt)
	nxt.Next = tail
	return root.Next
}
func reverse(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	root := &ListNode{0, head}
	for head.Next != nil {
		nxt := head.Next
		head.Next = nxt.Next
		nxt.Next = root.Next
		root.Next = nxt
	}
	return root.Next
}
