/*
 * @Author: ronin0322
 * @Date: 2022-09-19 22:54:54
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-23 21:14:09
 * @FilePath: /leetcode/codeforce822div2/b.cc
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
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                    cout << 1 << " ";
                else
                    cout << 0 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}