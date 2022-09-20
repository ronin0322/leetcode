/*
 * @Author: ronin0322
 * @Date: 2022-09-20 18:13:14
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-20 19:43:16
 * @FilePath: /leetcode/w.cc
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
/* index.cpp */
#include <bits/stdc++.h>
using namespace std;

bool check(long long *a, int x, int n, int m)
{
    int res = 0;
    for (int i = 0; i < m; i++)
    {
        res += ceil((double)a[i] / x);
        // cout << a[i] << " " << x << " " << ceil((double)a[i] / x) << endl;
    }
    if (res <= n)
        return true;
    else
        return false;
}
int main(int argc, char *argv[])
{
    int n, m;
    n = 6;
    m = 6;
    long long arr[1000] = {1, 1, 1, 1, 1, 1};
    long long sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum = max(arr[i], sum);
    }

    int l = arr[0], r = sum;
    while (l < r)
    {
        int mid = ((r - l) / 2) + l;
        if (check(arr, mid, n, m))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
    std::cout << "Hello World" << std::endl;
    return (0);
}