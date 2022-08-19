/*
 * @Author: ronin0322
 * @Date: 2022-08-17 09:22:27
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-18 01:43:29
 * @FilePath: /leetcode/main.cpp
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */

#include <bits/stdc++.h>

using namespace std;

void pri(vector<int> &queue)
{
    for (auto i = queue.begin(); i != queue.end(); i++)
        cout << *i << " " << endl;
}
int inSide(int x, int y, vector<vector<int>> arr)
{
    return x >= 0 && x < arr.size() && y >= 0 && y < arr.size();
}
void bfs(vector<vector<int>> arr)
{

    vector<int> dir = {0, 1, 0, -1, 0};
    vector<vector<int>> sign(10, vector<int>(10, 0));
    vector<vector<int>> queue;
    queue.push_back({0, 0});
    int l = 0;
    for (; l < queue.size();)
    {
        int r = queue.size();
        for (int i = l; i < r; i++)
        {
            auto cur = queue[i];
            for (int k = 0; k < 4; k++)
            {
                auto xx = cur[0] + dir[k], yy = cur[1] + dir[k + 1];
                if (inSide(xx, yy, arr) && sign[xx][yy] == 0)
                {
                    sign[xx][yy] = 1;
                    queue.push_back({xx, yy});
                }
            }
        }
        l = r;
    }
    for (int i = 0; i < queue.size(); i++)
        cout << arr[queue[i][0]][queue[i][1]] << " ";

    cout << endl;
}

int main()
{
    cout << "vector" << endl;
    vector<int> queue;
    queue.push_back(0);
    queue.push_back(0);
    queue.push_back(0);
    queue[0] = 1;
    queue[1] = 2;
    queue[2] = 3;
    // queue.push_back(1);
    // queue.push_back(2);
    // queue.push_back(3);
    pri(queue);
    cout << queue.back() << endl;
    queue.pop_back();
    pri(queue);
    cout << "map" << endl;
    unordered_map<int, int> ma;
    ma[1] = 1;
    ma[2] = 2;
    cout << ma[1] << endl;
    cout << ma[2] << endl;
    cout << ma[3] << endl;
    cout << ma[4] << endl;
    for (auto x = ma.begin(); x != ma.end(); x++)
        cout << x->first << " " << x->second << endl;
    cout << ma.size() << endl;

    cout << "stack" << endl;
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    // cout << s.pop() << endl;
    cout << "stack" << endl;
    vector<vector<int>> arr(10, vector<int>(10, 1));
    int brr[10] = {0, 1, 2, 4};
    cout << sizeof(brr) << endl;
    cout << length(arr) << endl;
    vector<int>
        brrr(brr, brr + sizeof(brr) / sizeof(int));
    cout << brrr.size() << endl;
    for (auto &x : brrr)
        cout << x << " ";
    cout << endl;
    // bfs(arr);
    return 0;
}