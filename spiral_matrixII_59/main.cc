/*
 * @Author: ronin0322
 * @Date: 2022-09-20 14:14:53
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-20 14:14:54
 * @FilePath: /leetcode/spiral_matrixII_59/main.cc
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool InSide(int x, int y, int n)
    {
        return x >= 0 && y >= 0 && x < n && y < n;
    }
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int num = 1;
        int x = 0, y = -1;
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (num <= n * n)
        {
            for (int i = 0; i < 4; i++)
            {
                auto dir = dirs[i];
                int nxt_x = x + dir.first, nxt_y = y + dir.second;
                while (InSide(nxt_x, nxt_y, n) && res[nxt_x][nxt_y] == 0)
                {
                    res[nxt_x][nxt_y] = num++;
                    nxt_x = nxt_x + dir.first;
                    nxt_y = nxt_y + dir.second;
                }
                if (num == n * n + 1)
                    break;
                x = nxt_x - dir.first;
                y = nxt_y - dir.second;
            }
        }
        return res;
    }
};