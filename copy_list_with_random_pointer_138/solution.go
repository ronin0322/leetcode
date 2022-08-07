/*
 * @Author: ronin0322
 * @Date: 2022-08-08 00:30:52
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-08 00:30:52
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
