/*
 * @Author: ronin0322
 * @Date: 2022-09-19 21:08:42
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-19 22:25:58
 * @FilePath: /leetcode/dfs.cc
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int x, y;
};
vector<vector<int>> down_block;
vector<vector<vector<Node>>> blocks;
vector<Node> target;
int n, m;
bool InSide(int x, int y)
{
    return x >= 0 && x < n && y < m && y >= 0;
}
bool block_down(int x, int y, int idx, int dirs, vector<Node> &location)
{
    for (int i = 0; i < blocks[idx][dirs].size(); i++)
    {
        auto cur = blocks[idx][dirs][i];
        // cout << idx << "???" << cur.x << " " << cur.y << endl;
        if (InSide(x + cur.x, y + cur.y) && down_block[x + cur.x][y + cur.y] == -1)
        {
            location.push_back(cur);
        }
        else
            return false;
    }
    for (auto node : location)
    {
        // cout << x + node.x << " " << y + node.y << " " << idx << endl;
        down_block[x + node.x][y + node.y] = idx;
    }
    // cout << endl;
    return true;
}

void block_up(int x, int y, int idx, vector<Node> &location)
{
    for (auto node : location)
    {
        down_block[x + node.x][y + node.y] = -1;
    }
}
bool check()
{
    auto block_num = 0;
    for (auto node : target)
    {
        if (down_block[node.x][node.y] != -1)
            return false;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (down_block[i][j] != -1)
                block_num++;

    if (block_num == n * m - target.size())
    {
        return true;
    }
    return false;
}
void dfs(int idx)
{

    if (idx == blocks.size())
    {
        if (check())
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                    printf("%2d ", down_block[i][j]);
                cout << endl;
            }
            cout << endl;
        }

        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (down_block[i][j] == -1)
                for (int k = 0; k < 4; k++)
                {
                    vector<Node> location(0);
                    if (block_down(i, j, idx, k, location))
                    {
                        dfs(idx + 1);
                        block_up(i, j, idx, location);
                    }
                }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    n = 3;
    m = 3;
    down_block = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
    target.push_back(Node{0, 0});
    target.push_back(Node{2, 1});
    target.push_back(Node{2, 2});
    vector<vector<Node>> block1(4);
    for (int i = 0; i < 4; i++)
    {
        block1[i].push_back(Node{0, 0});
        block1[i].push_back(Node{0, 1});
        block1[i].push_back(Node{1, 0});
        block1[i].push_back(Node{1, 1});
    }

    vector<vector<Node>> block2(4);
    block2[0].push_back(Node{0, 0});
    block2[0].push_back(Node{0, 1});

    block2[1].push_back(Node{0, 0});
    block2[1].push_back(Node{1, 0});

    block2[2].push_back(Node{0, 0});
    block2[2].push_back(Node{0, -1});

    block2[3].push_back(Node{0, 0});
    block2[3].push_back(Node{-1, 0});

    blocks.push_back(block1);
    blocks.push_back(block2);
    // for (auto x : blocks)
    // {
    //     for (auto y : x)
    //     {
    //         for (auto z : y)
    //             cout << z.x << " " << z.y << " ";
    //         cout << endl;
    //     }

    //     cout
    //         << endl;
    // }
    dfs(0);

    return 0;
}
