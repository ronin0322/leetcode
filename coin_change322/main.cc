/*
 * @Author: ronin0322
 * @Date: 2022-09-04 15:38:53
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-04 15:38:54
 * @FilePath: /leetcode/coin_change322/main.cc
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        const int maxint = 0x3fffffff;
        vector<int> sum(amount + 10, maxint);
        sum[0] = 0;
        for (auto coin : coins)
            for (int i = 0; i <= amount - coin; i++)
            {
                sum[i + coin] = min(sum[i + coin], sum[i] + 1);
            }
        return sum[amount] >= maxint ? -1 : sum[amount];
    }
};