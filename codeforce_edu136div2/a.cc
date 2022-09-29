/*
 * @Author: ronin0322
 * @Date: 2022-09-19 22:30:16
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-29 22:39:56
 * @FilePath: /leetcode/codeforce_edu136div2/a.cc
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
        int a, b;
        cin >> a >> b;
        auto res = true;
        for (int i = 1; i <= a; i++)
        {
            for (int j = 1; j <= b; j++)
                if (i >= 2 && j >= 2)
                {
                    res = false;
                    cout << i << " " << j << endl;
                    break;
                }
            if (!res)
                break;
        }

        if (res)
        {
            cout << "1 1" << endl;
        }
    }

    return 0;
}
