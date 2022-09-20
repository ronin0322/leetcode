/*
 * @Author: ronin0322
 * @Date: 2022-09-20 14:14:05
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-20 14:14:05
 * @FilePath: /leetcode/spiral_matrix_54/main.cc
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool InSide(int x, int y, int n, int m)
    {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> res;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int num = 0;
        int x = 0, y = -1;
        vector<vector<int>> vis(n, vector<int>(m, 1));
        while (res.size() < n * m)
        {
            for (int i = 0; i < 4; i++)
            {
                int nxt_x = x + dirs[i][0], nxt_y = y + dirs[i][1];
                while (InSide(nxt_x, nxt_y, n, m) && vis[nxt_x][nxt_y] != 0)
                {
                    res.push_back(matrix[nxt_x][nxt_y]);
                    vis[nxt_x][nxt_y] = 0;
                    nxt_x += dirs[i][0];
                    nxt_y += dirs[i][1];
                }
                if (res.size() == n * m)
                    break;
                x = nxt_x - dirs[i][0];
                y = nxt_y - dirs[i][1];
            }
        }
        return res;
    }
};
