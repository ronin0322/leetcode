/*
 * @Author: ronin0322
 * @Date: 2022-09-19 22:30:03
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-23 22:38:44
 * @FilePath: /leetcode/codeforce822div2/g.cc
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int n, x;
    cin >> n >> x;
    vector<int> arr(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> yu(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        yu[arr[i] % x]++;
    }
    int min_num = yu[0];
    int idx = 0;
    for (int i = 0; i < x; i++)
    {
        if (yu[i] < min_num)
        {
            idx = i;
            min_num = yu[i];
        }
    }
    // cout << idx << " " << min_num << endl;
    cout << idx + min_num * x << endl;
    return 0;
}
