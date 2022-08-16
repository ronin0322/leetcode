/*
 * @Author: ronin0322
 * @Date: 2022-08-14 15:10:01
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-14 16:46:46
 * @FilePath: /leetcode/merge_intervals_56/solution.cpp
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
        {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i)
        {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L)
            {
                merged.push_back({L, R});
            }
            else
            {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};

void pri (vector<int> i ) {
        cout << i[0] <<" " << i[1]<<endl;
}
int main()
{
    vector<vector<int>> req;
    req = {{1, 4}, {3, 4},{5, 7}, {8, 10}};
    Solution s;
    auto res = s.merge(req);
    for_each(res.begin(),res.end(),pri);
    
    // for (vector<int> x : res)
    // {
    //     for (int y : x)
    //     {
    //         cout << y;
    //     }
    // }
    cout<<endl;
    return 0;
}
