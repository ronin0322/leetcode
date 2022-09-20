/*
 * @Author: ronin0322
 * @Date: 2022-09-19 19:29:56
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-19 21:07:23
 * @FilePath: /leetcode/ww.cc
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int wgt, idx;
};
bool operator>(Node n1, Node n2)
{
    return n1.wgt > n2.wgt;
}
// bool operator<(Node n1, Node n2)
// {
//     return n1.wgt < n2.wgt;
// }
int Build(int n, vector<int> consts, vector<vector<int>> edge, vector<vector<int>> weight)
{
    priority_queue<Node, vector<Node>, greater<Node>> pri_que;
    for (int i = 0; i < n; i++)
    {
        pri_que.push(Node{consts[i], i});
    }
    vector<int> has_water(n + 1, 0);

    int cnt = 0;
    int res = 0;

    while (!pri_que.empty() && cnt < n)
    {
        auto cur = pri_que.top();
        while (has_water[cur.idx] != 0)
        {
            pri_que.pop();
            if (!pri_que.empty())
                cur = pri_que.top();
        }
        if (pri_que.empty())
            break;
        cout << cur.idx << " " << cur.wgt << endl;
        res += cur.wgt;
        has_water[cur.idx] = 1;
        pri_que.pop();
        cnt++;
        for (int i = 0; i < edge[cur.idx].size(); i++)
        {
            auto nxt = edge[cur.idx][i];
            if (has_water[nxt] == 0)
            {
                pri_que.push(Node{weight[cur.idx][i], nxt});
            }
        }
    }
    return res;
}
int main()
{
    int n = 4;
    vector<int> consts = {0, 100, 2, 3};
    vector<vector<int>> edge(n + 1);
    edge[0].push_back(1);
    // edge.push_back({2, 3});
    vector<vector<int>> weight(n + 1);
    weight[0].push_back(1);
    // weight.push_back({2, 2});

    cout << Build(n, consts, edge, weight) << endl;
    cout << "1" << endl;
    return 0;
}
