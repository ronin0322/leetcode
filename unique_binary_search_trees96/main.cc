/*
 * @Author: ronin0322
 * @Date: 2022-10-06 20:57:32
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-10-06 20:57:32
 * @FilePath: /leetcode/unique_binary_search_trees96/main.cc
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    unordered_map<int, int> data;
    int numTrees(int n)
    {
        auto v = data.find(n);
        if (v != data.end())
            return data[n];
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res += numTrees(i) * numTrees(n - i - 1);
        }
        data[n] = res;
        return res;
    }
};