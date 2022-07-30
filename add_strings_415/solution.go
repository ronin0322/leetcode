/*
 * @Author: ronin0322
 * @Date: 2022-07-30 15:54:53
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-07-30 16:34:22
 * @FilePath: /goproject/go-leetcode/add_strings_415/solution.go
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
package addstrings415

func addStrings(num1 string, num2 string) string {
	res := make([]byte, 0)
	sum := 0
	for len(num1) > 0 || len(num2) > 0 {
		if len(num1) > 0 {
			sum += int(num1[len(num1)-1] - '0')
			num1 = num1[:len(num1)-1]
		}
		if len(num2) > 0 {
			sum += int(num2[len(num2)-1] - '0')
			num2 = num2[:len(num2)-1]
		}
		res = append([]byte{byte('0' + sum%10)}, res...)
		sum = sum / 10
	}
	if sum > 0 {
		res = append([]byte{byte('0' + sum)}, res...)
	}
	return string(res)
}
