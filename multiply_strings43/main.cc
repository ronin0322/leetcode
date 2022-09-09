/*
 * @Author: ronin0322
 * @Date: 2022-09-09 09:16:27
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-09 09:16:28
 * @FilePath: /leetcode/multiply_strings43/main.cc
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        int n = num1.size(), m = num2.size();
        vector<int> res(n + m + 1, 0);
        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--)
            {
                res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        for (int i = n + m - 1; i > 0; i--)
        {
            res[i - 1] += res[i] / 10;
            res[i] = res[i] % 10;
        }
        string s = "";
        if (res[0] != 0)
            s += to_string(res[0]);
        for (int i = 1; i < n + m; i++)
        {
            s += to_string(res[i]);
        }
        return s;
    }
};