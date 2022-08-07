/*
 * @Author: ronin0322
 * @Date: 2022-08-07 17:00:54
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-07 17:00:54
 * @FilePath: /leetcode/binary_tree_right_side_view_199/solution.go
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */

package binarytreerightsideview199

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func rightSideView(root *TreeNode) []int {
	queue := make([]*TreeNode, 0)
	if root == nil {
		return []int{}
	}
	queue = append(queue, root)
	l := 0
	res := []int{}
	for l < len(queue) {
		r := len(queue)
		for i := l; i < r; i++ {
			if queue[i].Left != nil {
				queue = append(queue, queue[i].Left)
			}
			if queue[i].Right != nil {
				queue = append(queue, queue[i].Right)
			}
		}
		res = append(res, queue[r-1].Val)
		l = r
	}
	return res
}
