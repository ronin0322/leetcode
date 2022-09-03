/*
 * @Author: ronin0322
 * @Date: 2022-09-03 21:46:59
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-03 21:46:59
 * @FilePath: /leetcode/sliding_window_maximum_239/main.cpp
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<pair<int, int>> que(0);
        for (int i = 0; i < k; i++)
        {
            while (que.size() > 0 && nums[i] > que.back().first)
                que.pop_back();
            que.push_back({nums[i], i});
        }
        vector<int> res;
        for (int i = k; i < nums.size(); i++)
        {
            res.push_back(que.front().first);
            while (que.size() > 0 && nums[i] > que.back().first)
                que.pop_back();
            que.push_back({nums[i], i});
            while (que.size() > 0 && que.front().second <= i - k)
                que.pop_front();
        }
        res.push_back(que.front().first);
        return res;
    }
};