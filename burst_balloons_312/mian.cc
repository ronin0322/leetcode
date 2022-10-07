/*
 * @Author: ronin0322
 * @Date: 2022-10-07 18:21:01
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-10-07 18:21:01
 * @FilePath: /leetcode/burst_balloons_312/mian.cc
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.push_back(1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int i = n - 1; i >= 0; i--)
            nums[i + 1] = nums[i];
        nums[0] = 1;
        nums[n + 1] = 1;
        for (int k = 2; k <= n + 1; k++)
        {
            for (int i = 0; i + k <= n + 1; i++)
            {
                for (int j = i + 1; j < i + k; j++)
                {
                    dp[i][i + k] = max(dp[i][i + k], dp[i][j] + dp[j][i + k] + nums[i] * nums[j] * nums[i + k]);
                    // cout<<i<<" "<<i+k << " " <<dp[i][i+k] << endl;
                }
            }
        }
        return dp[0][n + 1];
    }
};

// class Solution {
// public:
//     int maxCoins(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> rec(n + 2, vector<int>(n + 2));
//         vector<int> val(n + 2);
//         val[0] = val[n + 1] = 1;
//         for (int i = 1; i <= n; i++) {
//             val[i] = nums[i - 1];
//         }
//         for (int i = n - 1; i >= 0; i--) {
//             for (int j = i + 2; j <= n + 1; j++) {
//                 for (int k = i + 1; k < j; k++) {
//                     int sum = val[i] * val[k] * val[j];
//                     sum += rec[i][k] + rec[k][j];
//                     rec[i][j] = max(rec[i][j], sum);
//                     cout<<i<<" "<<j<<" "<<rec[i][j]<<endl;
//                 }
//             }
//         }
//         return rec[0][n + 1];
//     }
// };
// 0 2 684
// 1 3 43776
// 2 4 102144
// 3 5 1344
// 0 3 44352
// 0 3 44352
// 1 4 14364
// 1 4 55872
// 2 5 4864
// 2 5 103740
// 0 4 56061
// 0 4 104424
// 0 4 104424
// 1 5 102828
// 1 5 102828
// 1 5 102828
// 0 5 102837
// 0 5 104500
// 0 5 104500
// 0 5 104500

// 3 5 1344
// 2 4 102144
// 2 5 6208
// 2 5 103740
// 1 3 43776
// 1 4 116508
// 1 4 116508
// 1 5 104424
// 1 5 104424
// 1 5 116697
// 0 2 684
// 0 3 44352
// 0 3 44352
// 0 4 116697
// 0 4 116697
// 0 4 116697
// 0 5 116706
// 0 5 116706
// 0 5 116706
// 0 5 116718
