/*
 * @Author: ronin0322
 * @Date: 2022-08-10 01:01:52
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-10 09:58:01
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

func findMedianSortedArrays2(nums1 []int, nums2 []int) float64 {
	n, m := len(nums1), len(nums2)
	if (n+m)&1 == 1 {
		return float64(findK2(nums1, nums2, (n+m+1)/2))
	}
	return float64(findK2(nums1, nums2, (n+m)/2)+findK2(nums1, nums2, (n+m)/2+1)) / 2
}

func findK2(nums1, nums2 []int, k int) int {
	k1, k2 := 0, 0
	for {
		if len(nums1) == k1 {
			return nums2[k-k1-1]
		}
		if len(nums2) == k2 {
			return nums1[k-k2-1]
		}
		if k-k1-k2 == 1 {
			return min(nums1[k1], nums2[k2])
		}
		sum := (k - k1 - k2) / 2
		mid1, mid2 := min(len(nums1)-1, k1+sum-1), min(len(nums2)-1, k2+sum-1)
		// fmt.Println(mid1,mid2,k,k1,k2)
		if nums1[mid1] < nums2[mid2] {
			k1 = mid1 + 1
		} else {
			k2 = mid2 + 1
		}
	}
}
