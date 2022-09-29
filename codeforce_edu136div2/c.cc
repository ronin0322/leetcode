/*
 * @Author: ronin0322
 * @Date: 2022-09-19 23:32:51
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-29 23:20:36
 * @FilePath: /leetcode/codeforce_edu136div2/c.cc
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
#include <bits/stdc++.h>

using namespace std;
vector<long long> win, lose;
int mod;
long long C(int a, int b)
{
    long long sum = 1;
    for (int i = 1; i <= a; i++)
    {
        sum = sum * b;
        b--;
        sum = sum / i;
    }
    // for (int i = a; i >= 1; i--)
    //     sum = sum / i;
    return sum % mod;
}
void getWin(int n)
{
    if (win[n] != 0)
    {
        return;
    }
    getWin(n - 2);
    win[n] = (lose[n - 2] + C((n / 2) - 1, n - 1)) % mod;
    lose[n] = (mod + C(n / 2, n) - win[n] - 1) % mod;
}

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    win = vector<long long>(61, 0);
    lose = vector<long long>(61, 0);
    win[2] = 1;
    lose[2] = 0;
    mod = 998244353;
    for (int tt = 0; tt < t; tt++)
    {
        int n;
        cin >> n;
        getWin(n);
        cout << win[n] << " " << lose[n] << " 1\n";
    }
    return 0;
}
