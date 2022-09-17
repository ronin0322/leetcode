/*
 * @Author: ronin0322
 * @Date: 2022-09-16 23:24:20
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-17 01:04:08
 * @FilePath: /leetcode/ww.cc
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int x, y, w;
};
vector<int> fa;
vector<int> fa_num;
bool Compare(Edge e1, Edge e2)
{
    return e1.w < e2.w;
}

int GetFa(int x)
{
    if (fa[x] == x)
    {
        return x;
    }
    fa[x] = GetFa(fa[x]);
}

int main()
{

    // ifstream infile;
    // infile.open("05");
    int n, m;
    int p;
    cin >> n >> m;
    p = (int)sqrt(n);
    vector<Edge> edge;
    for (int i = 0; i < m; i++)
    {
        auto cur = Edge{};
        cin >> cur.x >> cur.y >> cur.w;
        edge.push_back(cur);
    }
    // infile.close();
    sort(edge.begin(), edge.end(), Compare);
    // for (auto x : edge)
    // {
    //     cout << x.w << endl;
    // }
    fa = vector<int>(n + 10, 0);
    fa_num = vector<int>(n + 10, 1);
    for (int i = 0; i < n; i++)
        fa[i] = i;

    for (int i = 0; i < edge.size(); i++)
    {
        int xfa = GetFa(edge[i].x);
        int yfa = GetFa(edge[i].y);
        if (xfa == yfa)
        {
            continue;
        }
        if (fa_num[xfa] + fa_num[yfa] <= p)
        {
            fa_num[xfa] += fa_num[yfa];
            fa_num[yfa] = 0;
            fa[yfa] = xfa;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (fa_num[i] != 0 && fa_num[i] <= p)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (fa_num[i] + fa_num[j] <= p)
                {
                    int xfa = GetFa(i);
                    int yfa = GetFa(j);
                    fa_num[xfa] += fa_num[yfa];
                    fa_num[yfa] = 0;
                    fa[yfa] = xfa;
                }
            }
        }
    }

    vector<int> p_gone(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (p_gone[i])
            continue;
        int p_size = 1;
        vector<int> p_arr;
        int fa_i = GetFa(i);
        for (int j = 0; j < n; j++)
        {
            if (GetFa(j) == fa_i)
                p_arr.push_back(j);
        }
        cout << p_arr.size();
        for (auto x : p_arr)
        {
            p_gone[x] = 1;
            cout << " " << x;
        }

        cout << endl;
    }
    return 0;
}
