/*
 * @Author: ronin0322
 * @Date: 2022-09-20 00:05:51
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-24 01:22:46
 * @FilePath: /leetcode/codeforce822div2/d.cc
 * @Description:t;tt++
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
#include <bits/stdc++.h>
#define int long long
using namespace std;

bool Check(vector<int> &arr, int k, int n)
{
    if (arr[k] < 0 && k != n && k != 1)
        return false;
    vector<pair<int, int>> que;
    int sum = 0, max_sum = 0, min_sum = 0;
    for (int i = k; i <= n; i++)
    {
        sum += arr[i];
        min_sum = min(min_sum, sum);
        if (sum > max_sum)
        {
            que.push_back({sum - max_sum, min_sum - max_sum});
        }
        max_sum = max(max_sum, sum);
    }
    int l = 0;
    sum = 0;
    // for (auto x : que)
    // {
    //     cout << x.first << " " << x.second << endl;
    // }
    for (int i = k - 1; i >= 1; i--)
    {
        while (l < que.size() && sum + que[l].second >= 0)
        {
            sum += que[l++].first;
        }
        sum += arr[i];
        if (sum < 0)
            return false;
    }
    return true;
}

signed main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for (int tt; tt < t; tt++)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr;
        arr.push_back(0);
        for (int i = 1; i <= n; i++)
        {
            int num;
            cin >> num;
            arr.push_back(num);
        }
        arr.push_back(0);
        if (Check(arr, k, n))
        {
            cout << "YES" << endl;
            continue;
        }
        reverse(arr.begin(), arr.end());
        if (Check(arr, n - k + 1, n))
        {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}
