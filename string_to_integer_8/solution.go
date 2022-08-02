/*
 * @Author: ronin0322
 * @Date: 2022-08-03 01:45:27
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-03 01:45:28
 * @FilePath: /leetcode/string_to_integer_8/solution.go
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
package stringtointeger8

import "math"

func myAtoi(s string) int {

	var res, min, max, sign int64
	min, max = math.MinInt32, math.MaxInt32
	res = 0
	sign = 1
	i := 0
	if len(s) == 0 {
		return 0
	}
	for i < len(s) && s[i] == ' ' {
		i++
	}
	if i < len(s) && s[i] == '+' {
		i++
	} else if i < len(s) && s[i] == '-' {
		i++
		sign = -sign
	}
	for i < len(s) && s[i] >= '0' && s[i] <= '9' {
		res = res*10 + int64(s[i]-'0')
		if res*sign > max {
			res = max
			sign = 1
			break
		}
		if res*sign < min {
			res = min
			sign = 1
			break
		}
		i++
	}
	return int(res * sign)
}
