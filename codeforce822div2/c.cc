/*
 * @Author: ronin0322
 * @Date: 2022-09-19 23:32:51
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-23 22:57:33
 * @FilePath: /leetcode/codeforce822div2/c.cc
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
        char s[n];
        cin >> s;
        long long res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] == '0' || s[i - 1] == '2')
            {
                for (long long j = 1; (long long)j * i <= n; j++)
                {
                    if (s[j * i - 1] == '0')
                    {
                        s[j * i - 1] = '2';
                        res += i;
                    }
                    else if (s[j * i - 1] == '1')
                        break;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
