/*
 * @Author: ronin0322
 * @Date: 2022-08-03 01:45:45
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-13 11:12:36
 * @FilePath: /leetcode/main.go
 * @Description:
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
package main

import (
	"container/heap"
	"fmt"
	"math"
	"sort"
)

type arrHeap struct {
	arr sort.Float64Slice
}

func Solution(A []int) int {
	// write your code in Go (Go 1.4)
	arrH := &arrHeap{}
	var sum float64
	sum = 0.0
	for _, x := range A {
		fx := float64(x)
		heap.Push(arrH, fx)
		sum += fx
	}
	now := sum
	res := 0
	for arrH.Len() > 0 && now > sum/2 {
		cur := heap.Pop(arrH).(float64)
		res++
		newf := cur / 2
		now -= newf
		if cur == 0 {
			break
		}
		fmt.Println(cur, newf, now, sum)
		heap.Push(arrH, newf)
	}
	// fmt.Println(sum, now, arrH)
	// fmt.Println(res)
	return res
}
func (h arrHeap) Len() int           { return len(h.arr) }
func (h arrHeap) Less(i, j int) bool { return !h.arr.Less(i, j) }
func (h arrHeap) Swap(i, j int)      { h.arr.Swap(i, j) }
func (h *arrHeap) Pop() (v interface{}) {
	v = h.arr[len(h.arr)-1]
	h.arr = h.arr[:len(h.arr)-1]
	return v
}
func (h *arrHeap) Push(x interface{}) {
	h.arr = append(h.arr, x.(float64))
}
func main1() {

	// fmt.Println(Solution([]int{9, 11, 8, 1}))

	fmt.Println(Solution([]int{5, 19, 8, 1}))

	fmt.Println(Solution([]int{10, 10}))

	fmt.Println(Solution([]int{3, 0, 5}))
	fmt.Println(Solution([]int{1, 1, 1}))
	fmt.Println(Solution([]int{0, 0, 1}))
}

type Node struct {
	x, y int
}

const mo = 1e9 + 7

func findX(x, y int) int {
	if y != 0 {
		return findX(y, x%y)
	}
	return x
}
func Solutionx(X []int, Y []int) int {
	// write your code in Go (Go 1.4)
	res := 0
	sign := make(map[Node]int)
	for i := range X {
		sameX := findX(X[i], Y[i])
		newx, newy := X[i]/sameX, Y[i]/sameX
		res = (res + sign[Node{newy - newx, newy}]) % mo
		sign[Node{newx, newy}]++
	}
	return res
}

func main() {
	X := []int{}
	Y := []int{}
	// num := 100 // 4950
	// num := 100000 // 999949972
	num := 98765 // 877213202
	for i := 0; i < num; i++ {
		if i&1 == 0 {
			X = append(X, 1)
			Y = append(Y, 1)
		} else {
			X = append(X, 1)
			Y = append(Y, 4)
		}

	}
	fmt.Println(Solutionx(X, Y))
	// x := 4999950000
	// fmt.Println(x % mo)
}

func Solution3(A []int, X int, Y int) int {
	// write your code in Go (Go 1.4)
	res := math.MaxInt64
	wh := 0
	for i := 0; i < Y && i+(X-1)*Y < len(A); i++ {
		sum := 0
		for k := 0; k < X; k++ {
			sum += A[i+k*Y]
		}
		lst := i
		nxt := i + (X-1)*Y
		for nxt < len(A) {
			if sum < res {
				res = sum
				wh = i
			}
			sum -= A[lst]
			lst += Y
			nxt += Y
			if nxt >= len(A) {
				break
			}
			sum += A[nxt]
		}
	}
	fmt.Println(wh)
	return res
}

func main3() {
	A := []int{}
	num := 200000
	for i := 0; i < num; i++ {
		A = append(A, num-i-1)
	}
	X := 90000
	Y := 2
	fmt.Println(Solution3(A, X, Y))
	fmt.Println(Solution3([]int{10, 3, 4, 7}, 2, 3))
}
