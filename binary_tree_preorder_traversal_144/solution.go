/*
 * @Author: ronin0322
 * @Date: 2022-08-03 00:25:12
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-03 00:25:13
 * @FilePath: /leetcode/binary_tree_preorder_traversal_144/solution.go
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
package binarytreepreordertraversal144

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func preorderTraversal(root *TreeNode) []int {
	stack := make([]*TreeNode, 0)
	res := []int{}
	for len(stack) > 0 || root != nil {
		for root != nil {
			res = append(res, root.Val)
			stack = append(stack, root)
			root = root.Left
		}
		root = stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		root = root.Right
	}
	return res
}
