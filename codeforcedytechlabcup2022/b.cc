/*
 * @Author: ronin0322
 * @Date: 2022-09-19 22:54:54
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-10-07 23:40:15
 * @FilePath: /leetcode/codeforcedytechlabcup2022/b.cc
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
        long long l, r;

        cin >> l >> r;
        if (l > r)
        {
            cout << 0 << endl;
            continue;
        }
        long long ls = ceil(sqrt(l)), rs = floor(sqrt(r));
        // cout << ls << " " << rs << endl;
        long long res = 3 * (rs - ls);
        long long i = 0;
        if (ls > 1)
            for (i = (ls - 1) * (ls - 1); i < ls * ls; i += (ls - 1))
            {
                // cout << i << "??" << endl;
                if (i >= l)

                    res++;
            }

        for (i = rs * rs; i <= r; i += rs)
        {
            // cout << i << endl;
            if (i <= r)
                res++;
        }

        cout << res << endl;
    }
    return 0;
}