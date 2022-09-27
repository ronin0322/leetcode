/*
 * @Author: ronin0322
 * @Date: 2022-09-27 13:37:32
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-27 13:44:12
 * @FilePath: /leetcode/main.go
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
package main

import (
	"fmt"
)

func main() {
	data := map[int]int{
		1: 1,
		2: 2,
		3: 3,
	}
	// fmt.Println(data)
	// delK := []int{}
	for k, _ := range data {

		if k == 1 || k == 2 {
			delete(data, k)
		}
		fmt.Println(data)
	}
	// for _, x := range delK {
	// 	delete(data, x)
	// }
	fmt.Println(data)
	return
}
