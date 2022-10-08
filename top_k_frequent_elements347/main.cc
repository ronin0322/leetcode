/*
 * @Author: ronin0322
 * @Date: 2022-10-08 18:51:15
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-10-08 18:51:16
 * @FilePath: /leetcode/top_k_frequent_elements347/main.cc
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void divide(vector<pair<int, int>> &data, int k, int l, int r)
    {
        // auto mid = data[k-1];
        // swap(data[k-1],data[l]);
        if (l >= r)
            return;
        int ll = l;
        for (int z = l + 1; z < r; z++)
        {
            if (data[z].second >= data[l].second)
            {
                ll++;
                swap(data[z], data[ll]);
            }
        }
        swap(data[l], data[ll]);
        if (k <= ll + 1)
        {
            divide(data, k, l, ll);
        }
        else
            divide(data, k, ll + 1, r);
    }

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> data_map;
        for (auto x : nums)
            data_map[x]++;
        vector<pair<int, int>> data;
        for (auto [k, v] : data_map)
            data.push_back({k, v});
        for (auto pp : data)
            cout << pp.first << pp.second << endl;
        divide(data, k, 0, data.size());
        vector<int> res;
        for (int i = 0; i < k; i++)
            res.push_back(data[i].first);
        return res;
    }
};