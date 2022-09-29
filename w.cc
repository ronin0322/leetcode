/*
 * @Author: ronin0322
 * @Date: 2022-09-27 20:23:53
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-28 14:38:24
 * @FilePath: /leetcode/w.cc
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 3;
    vector<int> arr = {3, 2, 4, 3, 3};
    // 33544 34655 34666 34677 34678
    int res = 0, last = 0, lastnum = 0;
    for (auto x : arr)
    {
        if (x <= last)
        {
            if (1 + last - x > 0)
            {
                res += 1 + last - x;
            }
        }
        last = x;
    }
    cout << res << endl;
    return 0;
}
