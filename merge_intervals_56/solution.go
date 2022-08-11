/*
 * @Author: ronin0322
 * @Date: 2022-08-12 01:20:59
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-12 01:21:00
 * @FilePath: /leetcode/merge_intervals_56/solution.go
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
package mergeintervals56

import "sort"

func merge(intervals [][]int) [][]int {
	n := len(intervals)
	res := [][]int{}
	sort.Slice(intervals, func(x, y int) bool {
		return intervals[x][0] < intervals[y][0]
	})
	for i := 0; i < n; i++ {
		l, r := intervals[i][0], intervals[i][1]
		if len(res) == 0 || res[len(res)-1][1] < l {
			res = append(res, []int{l, r})
		} else {
			res[len(res)-1][1] = max(res[len(res)-1][1], r)
		}
	}
	return res
}
func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
