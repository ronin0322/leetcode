/*
 * @Author: ronin0322
 * @Date: 2022-08-16 09:43:29
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-16 10:15:29
 * @FilePath: /leetcode/main.cpp
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
class Solution
{
public:
    int myAtoi(string s)
    {
        int n = s.size();
        int index = 0;
        int sign = 1;
        long long num = 0;
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
        for (; index < n && s[index] >= '0' && s[index] <= '9';)
        {
            num = num * 10 + (s[index] - '0');
            index++;
        }
        return num * sign;
    }
};