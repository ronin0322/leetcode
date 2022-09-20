/*
 * @Author: ronin0322
 * @Date: 2022-09-19 23:32:51
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-20 00:33:43
 * @FilePath: /leetcode/codeforce821div2/c.cc
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
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            arr.push_back(num);
        }

        vector<vector<int>> res;
        if (arr[0] > arr[1])
        {
            res.push_back({0, 1});
            arr[0] = arr[1];
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (i == 0)
                continue;
            if (arr[i] > arr[i + 1])
            {
                if (arr[i - 1] < arr[i + 1])
                {
                    res.push_back({i - 1, i});
                    arr[i] = arr[i - 1];
                }
                else
                {
                    res.push_back({i, i + 1});
                    arr[i + 1] = arr[i];
                }
            }
        }
        if (arr[n - 2] > arr[n - 1])
        {
            res.push_back({n - 2, n - 1});
            arr[0] = arr[1];
        }
        cout << res.size() << endl;
        for (auto x : res)
        {
            cout << x[0] + 1 << " " << x[1] + 1 << endl;
        }
    }
    return 0;
}
