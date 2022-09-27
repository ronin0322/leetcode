/*
 * @Author: ronin0322
 * @Date: 2022-09-27 18:37:59
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-27 18:37:59
 * @FilePath: /leetcode/regular_expression_matching_10/main.cc
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int slen = s.size(), plen = p.size();
        auto match = [&](int i, int j)
        {
            // if (i == 0 && j == ) return true;
            if (p[i] == '.')
                return true;
            return p[i] == s[j];
        };
        vector<vector<int>> dp(plen + 1, vector<int>(slen + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= plen; i++)
        {
            for (int j = 0; j <= slen; j++)
            {
                // cout<<i<<" "<<j<<endl;
                if (i == 0 && j == 0)
                    continue;
                if (p[i - 1] != '*')
                {
                    if (j > 0 && match(i - 1, j - 1))
                        dp[i][j] = dp[i - 1][j - 1] | dp[i][j];
                }
                else
                {
                    dp[i][j] = dp[i][j] | dp[i - 2][j];
                    if (j > 0 && match(i - 2, j - 1))
                    {
                        dp[i][j] = dp[i][j] | dp[i][j - 1];
                    }
                }
            }
        }
        for (auto i : dp)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        if (dp[plen][slen])
            return true;
        return false;
        // return dp[plen][slen];
    }
};