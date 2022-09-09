/*
 * @Author: ronin0322
 * @Date: 2022-09-09 10:17:50
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-09 10:17:50
 * @FilePath: /leetcode/longest_valid_parentheses32/main.cc
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int left = 0, right = 0;
        int res = 0;
        for (auto c : s)
        {
            if (c == '(')
                left++;
            if (c == ')')
                right++;
            if (left == right)
                res = max(res, left + right);
            if (right > left)
            {
                left = 0;
                right = 0;
            }
        }
        left = 0, right = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            auto c = s[i];
            if (c == '(')
                left++;
            if (c == ')')
                right++;
            if (left == right)
                res = max(res, left + right);
            if (right < left)
            {
                left = 0;
                right = 0;
            }
        }
        return res;
    }
};