/*
 * @Author: ronin0322
 * @Date: 2022-09-19 22:30:16
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-23 20:30:37
 * @FilePath: /leetcode/codeforce822div2/a.cc
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
        vector<long long> arr;
        for (int i = 0; i < n; i++)
        {
            long long num = 0;
            cin >> num;
            arr.push_back(num);
        }
        sort(arr.begin(), arr.end());
        long long res = 0x7fffffff;
        for (int i = 2; i < n; i++)
        {
            res = min(res, abs(arr[i] - arr[i - 1]) + abs(arr[i - 1] - arr[i - 2]));
        }
        cout << res << endl;
    }

    return 0;
}
