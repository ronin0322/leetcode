/*
 * @Author: ronin0322
 * @Date: 2022-08-02 08:53:01
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-02 09:20:31
 * @FilePath: /leetcode/ binary_tree_inorder_traversal_94/solution.go
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */

package binary_tree_inorder_traversal_94

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func inorderTraversal(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}
	l := inorderTraversal(root.Left)
	res := []int{root.Val}
	r := inorderTraversal(root.Right)
	return append(l, append(res, r...)...)
}

func inorderTraversal2(root *TreeNode) []int {
	stack := []*TreeNode{}
	cur := root
	res := []int{}
	for len(stack) > 0 || cur != nil {
		for cur != nil {
			stack = append(stack, cur)
			cur = cur.Left
		}
		cur = stack[len(stack)-1]
		res = append(res, cur.Val)
		stack = stack[:len(stack)-1]
		cur = cur.Right
	}
	return res
}
