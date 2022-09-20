/*
 * @Author: ronin0322
 * @Date: 2022-09-19 22:54:54
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-19 23:24:49
 * @FilePath: /leetcode/codeforce821div2/b.cc
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++)
    {
        int n, x, y;
        cin >> n >> x >> y;
        int a, b;
        if (x < y)
            swap(x, y);
        if (n == 1 || y != 0 || x == 0 || (n - 1) % x != 0)
        {
            cout << -1 << endl;
            continue;
        }
        for (int j = 0; j < x; j++)
            cout << 1 << " ";
        for (int i = x + 1; i < n; i += x)
        {
            for (int j = 0; j < x; j++)
                cout << i + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}