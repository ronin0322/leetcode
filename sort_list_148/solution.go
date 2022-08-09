/*
 * @Author: ronin0322
 * @Date: 2022-08-09 01:20:06
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-09 09:54:58
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

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func sortList2(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	prehead := &ListNode{Next: head}
	l := 0
	for cur := head; cur != nil; cur = cur.Next {
		l++
	}
	for length := 1; length < l; length <<= 1 {
		pre, cur := prehead, prehead.Next
		for cur != nil {
			head1 := cur
			for i := 0; cur != nil && cur.Next != nil && i < length-1; i++ {
				cur = cur.Next
			}
			head2 := cur.Next
			cur.Next = nil
			cur = head2
			for i := 0; cur != nil && cur.Next != nil && i < length-1; i++ {
				cur = cur.Next
			}
			nxt := cur
			if cur != nil {
				nxt = cur.Next
				cur.Next = nil
			}
			// fmt.Println(head1.Val,head2.Val,pre.Val)
			pre.Next = merge2(head1, head2)
			cur = nxt
			for pre.Next != nil {
				pre = pre.Next
				// fmt.Printf("%d ",pre.Val)
			}
			// fmt.Println()
		}
	}
	return prehead.Next
}
func merge2(left, right *ListNode) *ListNode {
	root := &ListNode{}
	prehead := root
	for left != nil && right != nil {
		if left.Val < right.Val {
			root.Next = left
			left = left.Next
		} else {
			root.Next = right
			right = right.Next
		}
		root = root.Next
	}
	if left != nil {
		root.Next = left
	}
	if right != nil {
		root.Next = right
	}
	return prehead.Next
}
