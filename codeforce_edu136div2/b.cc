/*
 * @Author: ronin0322
 * @Date: 2022-09-19 22:54:54
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-29 22:48:17
 * @FilePath: /leetcode/codeforce_edu136div2/b.cc
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
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> a(n, 0);
        a[0] = arr[0];
        auto res = true;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] + a[i - 1] >= 0 && a[i - 1] - arr[i] >= 0 && arr[i] + a[i - 1] != a[i - 1] - arr[i])
            {
                cout << -1 << endl;
                res = false;
                break;
            }
            else
                a[i] = arr[i] + a[i - 1];
        }
        if (!res)
            continue;
        for (auto x : a)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}