/*
 * @Author: ronin0322
 * @Date: 2022-09-03 22:59:06
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-03 23:00:24
 * @FilePath: /leetcode/minimum_mindow_substring_79/main.cc
 * @Description:
 *
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.size(), m = t.size();
        unordered_map<char, int> t_count, s_count;
        for (int i = 0; i < m; i++)
            t_count[t[i]]++;
        int all_num = 0;
        int res_left = 0, res_right = -1, res = INT_MAX;
        int last = 0;
        for (int i = 0; i < n; i++)
        {
            if (t_count[s[i]] > s_count[s[i]])
            {
                all_num++;
            }
            s_count[s[i]]++;
            if (all_num == m)
            {
                while (s_count[s[last]] > t_count[s[last]])
                {
                    s_count[s[last]]--;
                    last++;
                }
                if (i - last < res)
                {
                    res = i - last;
                    res_left = last;
                    res_right = i;
                }
            }
        }
        cout << res_left << " " << res_right << " " << res << endl;
        return s.substr(res_left, res_right - res_left + 1);
    }
};

int main()
{

    return 0;
}