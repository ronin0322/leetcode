package binarytreemaximumpathsum124

/*
 * @Author: ronin0322
 * @Date: 2022-08-02 01:15:35
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-02 01:15:35
 * @FilePath: /leetcode/binary_tree_maximum_path_sum_124/solution.go
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxPathSum(root *TreeNode) int {
	res := root.Val
	var dfs func(root *TreeNode)
	dp := map[*TreeNode]*dpNode{}
	dfs = func(root *TreeNode) {
		cur := &dpNode{}
		leftMax := root.Val
		if root.Left != nil {
			dfs(root.Left)
			leftMax = dp[root.Left].Max + root.Val
		}
		rightMax := root.Val
		if root.Right != nil {
			dfs(root.Right)
			rightMax = dp[root.Right].Max + root.Val
		}
		cur.Max = max(root.Val, max(leftMax, rightMax))
		dp[root] = cur
		res = max(res, max(cur.Max, leftMax+rightMax-root.Val))
		res = max(res, max(leftMax, rightMax))
	}
	dfs(root)
	return res
}

type dpNode struct {
	Max int
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}
