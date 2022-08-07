/*
 * @Author: ronin0322
 * @Date: 2022-08-07 17:06:11
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-07 17:06:11
 * @FilePath: /leetcode/climbing_stairs_70/solution.go
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
package climbingstairs70

func climbStairs(n int) int {
	if n == 0 {
		return 0
	}
	if n == 1 {
		return 1
	}
	if n == 2 {
		return 2
	}
	pre, ppre, cur := 2, 1, 0
	for i := 3; i <= n; i++ {
		cur = pre + ppre
		ppre, pre = pre, cur
	}
	return cur
}
