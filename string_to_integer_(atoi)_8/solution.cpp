/*
 * @Author: ronin0322
 * @Date: 2022-08-16 10:19:48
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-16 10:22:05
 * @FilePath: /leetcode/string_to_integer_(atoi)_8/solution.cpp
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int myAtoi(string s)
    {
        int n = s.size();
        int index = 0;
        int sign = 1;
        int num = 0;
        for (; index < n && s[index] == ' ';)
            index++;
        if (index < n && s[index] == '+')
        {
            sign = 1;
            index++;
        }
        else if (index < n && s[index] == '-')
        {
            sign = -1;
            index++;
        }
        cout << sign << index;
        for (; index < n && s[index] >= '0' && s[index] <= '9';)
        {
            if (num * sign > INT_MAX / 10 || (num * sign == INT_MAX / 10 && (s[index] - '0') > INT_MAX % 10))
                return INT_MAX;
            if (num * sign < INT_MIN / 10 || (num * sign == INT_MIN / 10 && (s[index] - '0') > 7))
                return INT_MIN;
            num = num * 10 + (s[index] - '0');
            index++;
        }
        return num * sign;
    }
};