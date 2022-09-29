/*
 * @Author: ronin0322
 * @Date: 2022-09-20 00:05:51
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-30 01:02:04
 * @FilePath: /leetcode/codeforce_edu136div2/d.cc
 * @Description:t;tt++
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> edge;

int length, num;
int dfs(int root)
{
    int hei = 0;
    for (auto x : edge[root])
    {
        hei = max(dfs(x), hei);
    }
    hei++;
    if (hei >= length)
    {
        num++;
        return 0;
    }
    return hei;
}

int Check(int mid, int k)
{
    length = mid;
    num = 0;
    for (auto x : edge[1])
        for (auto y : edge[x])
            dfs(y);
    if (num <= k)
        return 1;
    return 0;
}
int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++)
    {
        int n, k;
        cin >> n >> k;
        edge = vector<vector<int>>(n + 1, vector<int>(0));
        for (int i = 2; i <= n; i++)
        {
            int j;
            cin >> j;
            edge[j].push_back(i);
        }

        int l = 1, r = n - 1;
        // for (int i = 1; i <= n - 1; i++)
        // {
        //     if (Check(i, k))
        //     {
        //         cout << i << endl;
        //         break;
        //     }
        // }
        while (l < r)
        {
            auto mid = (l + r) / 2;
            // cout << l << " " << r << endl;
            if (Check(mid, k))
                r = mid;
            else
                l = mid + 1;
        }
        cout << l << endl;
    }
    return 0;
}
