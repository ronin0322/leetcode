/*
 * @Author: ronin0322
 * @Date: 2022-09-19 22:54:54
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-10-02 23:07:20
 * @FilePath: /leetcode/codeforce824div2/b.cc
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
        vector<int> arr(n + 1, 0);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int res = 0;
        int min_p = arr[0];
        for (int i = 0; i < n; i++)
            min_p = min(min_p, arr[i]);
        min_p = min_p * 2 - 1;
        for (int i = 0; i < n; i++)
            if (arr[i] / min_p > 0)
            {
                res += arr[i] / min_p;
                if (arr[i] % min_p == 0)
                    res--;
            }
        cout << res << endl;
    }
    return 0;
}