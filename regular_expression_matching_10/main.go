/*
 * @Author: ronin0322
 * @Date: 2022-09-27 18:38:32
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-27 18:38:33
 * @FilePath: /leetcode/regular_expression_matching_10/main.go
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
package main

import "fmt"

func isMatch(s string, p string) bool {
	sLen, pLen := len(s), len(p)
	dp := make([][]bool, pLen+1)
	for i := range dp {
		dp[i] = make([]bool, sLen+1)
	}
	dp[0][0] = true
	for i := range p {
		if i > 0 && p[i] == '*' {
			dp[i+1][0] = dp[i+1][0] || dp[i-1][0]
		}
		for j := range s {
			if p[i] == s[j] {
				dp[i+1][j+1] = dp[i+1][j+1] || dp[i][j]
			}
			if p[i] == '.' {
				dp[i+1][j+1] = dp[i+1][j+1] || dp[i][j]
			}
			if i > 0 && p[i] == '*' {
				dp[i+1][j+1] = dp[i+1][j+1] || dp[i-1][j+1]
			}
			if i > 0 && p[i] == '*' && (p[i-1] == '.' || p[i-1] == s[j]) {
				dp[i+1][j+1] = dp[i+1][j+1] || dp[i+1][j] || dp[i][j]
			}
		}
	}
	for i := range p {
		for j := range s {
			fmt.Print(dp[i][j])
		}
		fmt.Println()
	}
	return dp[pLen][sLen]
}
