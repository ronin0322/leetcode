/*
 * @Author: ronin0322
 * @Date: 2022-08-06 10:18:53
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-06 10:18:54
 * @FilePath: /leetcode/binary_search_704/solution.go
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
package binary_search_704

func search(nums []int, target int) int {
	left, right := 0, len(nums)
	for left < right {
		mid := (right-left)/2 + left
		if nums[mid] == target {
			return mid
		}
		if nums[mid] > target {
			right = mid
		} else {
			left = mid + 1
		}
	}
	if left < len(nums) && nums[left] == target {
		return left
	}
	return -1
}
