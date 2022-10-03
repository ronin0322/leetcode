/*
 * @Author: ronin0322
 * @Date: 2022-09-19 23:32:51
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-10-02 23:54:22
 * @FilePath: /leetcode/codeforce824div2/c.cc
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
#include <bits/stdc++.h>

using namespace std;
int cir_num;
bool dfs(vector<int> &cir, vector<int> &lst, int ch, int target)
{
    if (lst[ch] != 0)
        return false;
    while (ch != target && cir[ch] != 0)
    {
        ch = cir[ch];
    }
    if (ch == target)
    {
        if (cir_num < 25)
            return false;
        else
            return true;
    }

    return true;
}

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
        vector<int> cir(300, 0);
        vector<int> lst(300, 0);
        cir_num = 0;
        for (int j = 0; j < n; j++)
        {
            if (cir[s[j]] != 0)
            {
                cout << (char)cir[s[j]];
                continue;
            }
            int i = 0;
            for (; i < 26; i++)
                if (i + 'a' != s[j])
                {
                    if (dfs(cir, lst, i + 'a', s[j]))
                    {
                        cir[s[j]] = i + 'a';
                        lst[i + 'a'] = s[j];
                        cir_num++;
                        // for (int ii = 0; ii < 2; ii++)
                        // {
                        //     cout << cir[ii + 'a'] << " " << lst[ii + 'a'] << endl;
                        // }
                        break;
                    }
                }
            if (i != 26)
                cout << (char)(i + 'a');
        }
        cout << endl;
    }
    return 0;
}
