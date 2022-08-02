/*
 * @Author: ronin0322
 * @Date: 2022-08-03 00:54:03
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-03 00:54:04
 * @FilePath: /leetcode/binary_tree_postorder_traversal_145/solution.go
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
package binarytreepostordertraversal145

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func postorderTraversal(root *TreeNode) []int {
	stack := make([]*TreeNode, 0)
	res := make([]int, 0)
	var pre *TreeNode
	for len(stack) > 0 || root != nil {
		for root != nil {
			stack = append(stack, root)
			root = root.Left
		}
		root = stack[len(stack)-1]
		if root.Right == nil || root.Right == pre {
			res = append(res, root.Val)
			stack = stack[:len(stack)-1]
			pre = root
			root = nil
		} else {
			root = root.Right
		}
	}
	return res
}
