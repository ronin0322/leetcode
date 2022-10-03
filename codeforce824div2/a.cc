/*
 * @Author: ronin0322
 * @Date: 2022-09-19 22:30:16
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-10-02 22:53:22
 * @FilePath: /leetcode/codeforce824div2/a.cc
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
        int num = n - 3;
        cout << num / 3 - 1 << endl;
    }

    return 0;
}
