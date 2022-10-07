/*
 * @Author: ronin0322
 * @Date: 2022-09-19 23:32:51
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-10-08 00:59:36
 * @FilePath: /leetcode/codeforcedytechlabcup2022/c.cc
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
        vector<int> x(4);
        vector<int> y(4);
        for (int i = 0; i < 4; i++)
        {
            cin >> x[i] >> y[i];
        }
        int xc, yc;
        if (x[0] == x[1] || x[0] == x[2])
            xc = x[0];
        else
            xc = x[1];
        if (y[0] == y[1] || y[0] == y[2])
            yc = y[0];
        else
            yc = y[1];
        // cout << xc << yc << endl;
        if ((xc > 1 && xc < n) || ((xc == 1 || xc == n) && (yc != 1 && yc != n)))
        {
            xc = xc % 2;
            x[3] = x[3] % 2;
        }
        else
        {
            // yc = yc % 2;
            if (x[3] == 1 || x[3] == n)
                y[3] = y[3] % 2;
            if (abs(xc - x[3]) + abs(yc % 2 - y[3]) < 2)
            {
                cout << "YES" << endl;
                continue;
            }
            if ((yc > 1 && xc - yc + 1 == x[3] - y[3]) || (yc < n && xc + yc + 1 == x[3] + y[3]))
            {
                cout << "YES" << endl;
                continue;
            }
        }

        if ((yc > 1 && yc < n) || ((yc == 1 || yc == n) && (xc != 1 && xc != n)))
        {
            yc = yc % 2;
            y[3] = y[3] % 2;
        }
        else
        {
            // xc = xc % 2;
            if (y[3] == 1 || y[3] == n)
                x[3] = x[3] % 2;
            if (abs(xc % 2 - x[3]) + abs(yc - y[3]) < 2)
            {
                cout << "YES" << endl;
                continue;
            }

            if ((xc > 1 && xc - 1 - yc == x[3] - y[3]) || (xc < n && xc + yc + 1 == x[3] + y[3]))
            {
                cout << "YES" << endl;
                continue;
            }
        }

        // cout << xc << yc << endl;
        // cout << x[3] << y[3] << endl;
        if (abs(xc - x[3]) + abs(yc - y[3]) < 2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

// 100 8 1 1 1 2 2 2 6 7