/*
 * @Author: ronin0322
 * @Date: 2022-09-20 00:05:51
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-20 00:14:18
 * @FilePath: /leetcode/codeforce821div2/d.cc
 * @Description:t;tt++
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
    for (int tt; tt < t; tt++)
    {
        long long n, x, y;
        cin >> n >> x >> y;
        string a, b;
        cin >> a;
        cin >> b;
        string c;
        int num = 0;
        vector<int> location(0);
        for (int i = 0; i < n; i++)
        {
            if (a[i] == b[i])
                c += '0';
            else
            {
                c += '1';
                num++;
                location.push_back(i);
            }
        }
        if (num % 2 == 1)
        {
            cout << -1 << endl;
            continue;
        }
        if (num == 0)
        {
            cout << 0 << endl;
            continue;
        }
        if (num == 2)
        {
            if (location[0] + 1 == location[1])
            {
                cout << min(x, y * 2) << endl;
                continue;
            }
        }
        cout << y * num / 2 << endl;
    }
    return 0;
}
