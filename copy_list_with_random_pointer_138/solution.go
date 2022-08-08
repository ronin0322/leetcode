/*
 * @Author: ronin0322
 * @Date: 2022-08-08 00:30:52
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-08 09:04:01
 * @FilePath: /leetcode/copy_list_with_random_pointer_138/solution.go
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */

package copylistwithrandompointer138

type Node struct {
	Val    int
	Next   *Node
	Random *Node
}

func copyRandomList(head *Node) *Node {
	prehead := &Node{}
	root := prehead
	cur := head
	data := map[*Node]*Node{}
	for cur != nil {
		prehead.Next = &Node{cur.Val, nil, nil}
		data[cur] = prehead.Next
		cur = cur.Next
		prehead = prehead.Next
	}
	cur = head
	prehead = root.Next
	for cur != nil {
		prehead.Random = data[cur.Random]
		cur = cur.Next
		prehead = prehead.Next
	}
	return root.Next

}

/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

func copyRandomList2(head *Node) *Node {
	root := head
	if head == nil {
		return nil
	}
	for root != nil {
		newNode := &Node{root.Val, root.Next, nil}
		root.Next = newNode
		root = root.Next.Next
	}
	root = head
	for root != nil {
		if root.Random != nil {
			root.Next.Random = root.Random.Next
		} else {
			root.Next.Random = nil
		}

		root = root.Next.Next
	}
	root = head
	res := root.Next
	for root != nil {
		nxt := root.Next.Next
		if root.Next.Next == nil {
			root.Next.Next = nil
		} else {
			root.Next.Next = root.Next.Next.Next
		}
		root.Next = nxt
		root = root.Next
	}
	return res
}
