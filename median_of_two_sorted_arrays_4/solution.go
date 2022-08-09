/*
 * @Author: ronin0322
 * @Date: 2022-08-10 01:01:52
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-10 01:01:52
 * @FilePath: /leetcode/median_of_two_sorted_arrays_4/solution.go
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
package medianoftwosortedarrays4

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	n, m := len(nums1), len(nums2)
	if (n+m)&1 == 1 {
		return float64(findK(nums1, nums2, (n+m)/2))
	}
	return float64((findK(nums1, nums2, (n+m)/2) + findK(nums1, nums2, (n+m)/2-1))) / 2
}
func findK(nums1, nums2 []int, k int) int {
	mid := (k - 1) / 2
	if mid < 0 {
		mid = 0
	}
	k1, k2 := min(len(nums1)-1, mid), min(len(nums2)-1, mid)
	if k1 == -1 {
		return nums2[k]
	}
	if k2 == -1 {
		return nums1[k]
	}
	if k == 0 {
		return min(nums1[0], nums2[0])
	}
	if nums1[k1] < nums2[k2] {
		return findK(nums1[k1+1:], nums2, k-k1-1)
	} else {
		return findK(nums1, nums2[k2+1:], k-k2-1)
	}
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
