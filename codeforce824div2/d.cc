/*
 * @Author: ronin0322
 * @Date: 2022-09-19 22:30:16
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-10-06 20:56:38
 * @FilePath: /leetcode/codeforce824div2/d.cc
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
    t = 1;
    // cin >> t;
    for (int tt = 0; tt < t; tt++)
    {
        int n, k;
        cin >> n >> k;
        unordered_map<long long, int> d;
        unordered_map<long long, int> se;
        for (int i = 0; i < n; i++)
        {
            long long o = 0;
            long long num = 0;
            for (int j = 0; j < k; j++)
            {
                cin >> o;
                num = num * 3 + o;
            }
            d[num] = 1;
            se[num] = 0;
        }
        // for (auto data0 : d)
        //     cout << data0.first << endl;
        // cout << endl;
        long long res = 0;

        for (auto data0 : d)
        {
            for (auto data1 : d)
                if (data0.first != data1.first)
                {
                    long long a0 = data0.first;
                    long long a1 = data1.first;
                    long long a2 = 0;
                    long long c = 1;
                    while (a0 > 0 || a1 > 0)
                    {
                        if (a0 % 3 == a1 % 3)
                        {
                            a2 += c * (a0 % 3);
                        }
                        else
                        {
                            a2 += c * (3 - (a0 % 3) - (a1 % 3));
                        }
                        c = c * 3;
                        a0 = a0 / 3;
                        a1 = a1 / 3;
                    }
                    auto x = d.find(a2);
                    if (x != d.end())
                    {
                        // cout << data0.first << " " << data1.first << " " << a2 << endl;
                        se[data0.first]++;
                        se[data1.first]++;
                        se[a2]++;
                    }
                    // cout << "hh" << endl;
                }
        }
        for (auto s : se)
        {
            // cout << s.first << " " << s.second << endl;
            s.second = s.second / 6;
            if (s.second >= 2)
                res += s.second * (s.second - 1) / 2;
        }
        cout << res << endl;
    }

    return 0;
}
