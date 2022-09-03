/*
 * @Author: ronin0322
 * @Date: 2022-09-03 21:43:42
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-03 21:45:54
 * @FilePath: /leetcode/main.cpp
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s = "abcabc";
    s = "sd" + s + "d";
    deque<pair<int, int>> que;
    que.push_back({1, 2});
    cout << que.back().first << endl;

    map<int, int> data;
    data[1] = 1;
    cout << data.begin()->first;
    // cout << a.getNum(s) << endl;
}