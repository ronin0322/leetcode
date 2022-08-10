/*
 * @Author: ronin0322
 * @Date: 2022-08-11 01:28:46
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-11 01:28:47
 * @FilePath: /leetcode/generate_parentheses_22/solution.go
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */

package generateparentheses22

func generateParenthesis(n int) []string {
	var dfs func(x int)
	arr := []string{}
	s := []byte{}
	dfs = func(x int) {
		if x == n*2 {
			arr = append(arr, string(append([]byte{}, s...)))
			return
		}
		s = append(s, '(')
		dfs(x + 1)
		s[len(s)-1] = ')'
		dfs(x + 1)
		s = s[:len(s)-1]
	}
	dfs(0)
	// fmt.Println(arr)
	res := []string{}
	for _, x := range arr {
		if check(x) {
			res = append(res, x)
		}
	}
	return res
}

func check(s string) bool {
	stack := []byte{}
	for i := 0; i < len(s); i++ {
		if s[i] == '(' {
			stack = append(stack, s[i])
		} else {
			if len(stack) > 0 && stack[len(stack)-1] == '(' {
				stack = stack[:len(stack)-1]
			} else {
				return false
			}
		}
	}
	if len(stack) > 0 {
		return false
	}
	return true
}
