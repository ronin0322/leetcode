/*
 * @Author: ronin0322
 * @Date: 2022-09-19 22:30:16
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-10-07 23:09:14
 * @FilePath: /leetcode/codeforcedytechlabcup2022/a.cc
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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> let(26, 0);
        for (auto c : s)
            let[c - 'a']++;
        for (int i = 0; i < n; i += n / k)
        {
            int idx = 0;
            int nums = n / k;
            for (idx = 0; idx < n / k; idx++)
                if (let[idx] == 0)
                    break;
                else
                    let[idx]--;
            // nums -= idx;
            // if (nums > 0)
            //     for (int r = 26; nums > 0; r--)
            //     {
            //         while (nums > 0 && let[r] > 0)
            //         {
            //             // let[r]--;
            //             nums--;
            //         }
            //     }
            cout << (char)('a' + idx);
        }
        cout << endl;
    }

    return 0;
}
