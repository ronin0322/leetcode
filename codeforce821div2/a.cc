/*
 * @Author: ronin0322
 * @Date: 2022-09-19 22:30:16
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-19 22:47:05
 * @FilePath: /leetcode/codeforce821div2/a.cc
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
        int n, k;
        cin >> n >> k;
        vector<long long> arr;
        for (int i = 0; i < n; i++)
        {
            int num = 0;
            scanf("%d", &num);
            arr.push_back(num);
        }
        long long res = 0;
        for (int i = 0; i < k; i++)
        {
            long long max_num = 0;
            for (int j = i; j < n; j += k)
            {
                max_num = max(max_num, arr[j]);
            }
            res += max_num;
        }
        cout << res << endl;
    }

    return 0;
}
