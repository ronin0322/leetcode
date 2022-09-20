/*
 * @Author: ronin0322
 * @Date: 2022-09-14 15:52:31
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-17 17:21:26
 * @FilePath: /leetcode/w.cc
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
#include <bits/stdc++.h>

using namespace std;
// 00001111,

struct Node
{
    int l, r;
};

bool Compare(Node n1, Node n2)
{
    if (n1.l < n2.l)
    {
        return true;
    }
    if (n1.l == n2.l)
    {
        return n1.r < n2.r;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int n, p, q;
    cin >> n >> p >> q;
    vector<int> l, r, t;
    int num = 0;
    int min_l = 0x7fffffff, max_r = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        l.push_back(num);
        min_l = min(min_l, num);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        r.push_back(num);
        max_r = max(max_r, num);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        t.push_back(num);
    }
    vector<Node> arr_one;
    vector<Node> arr_two;
    for (int i = 0; i < n; i++)
    {
        if (t[i] == 1)
        {
            arr_one.push_back(Node{l[i], r[i]});
        }
        else
        {
            arr_two.push_back(Node{l[i], r[i]});
        }
    }
    sort(arr_one.begin(), arr_one.end(), Compare);
    sort(arr_two.begin(), arr_two.end(), Compare);
    int pt1 = 0, sum1 = 0, pt2 = 0, sum2 = 0, res = 0;
    priority_queue<int, vector<int>, greater<int>> stk, stk2;
    // priority_queue<int, vector<int>, greater<int>> stk2;

    while (pt1 < arr_one.size() || pt2 < arr_two.size())
    {
        if (sum1 >= p && sum2 >= q)
        {
            int end = min(stk.top(), stk2.top());
            res += end - max(arr_one[pt1 - 1].l, arr_two[pt2 - 1].l) + 1;
            if (stk.top() <= end)
                pt1++;
            else
                pt2++;
            cout << "yes" << endl;
        }
        while (pt1 < arr_one.size() && sum1 < p)
        {
            while (stk.size() > 0 && stk.top() < arr_one[pt1].l)
            {
                sum1--;
                stk.pop();
            }
            sum1++;
            stk.push(arr_one[pt1].r);
            pt1++;
        }
        // cout << pt1 << "+" << sum1 << endl;
        while (pt2 < arr_two.size() && sum2 < q)
        {
            while (stk2.size() > 0 && stk2.top() < arr_two[pt2].l)
            {
                sum2--;
                stk2.pop();
            }
            sum2++;
            stk2.push(arr_two[pt2].r);
            pt2++;
        }
        // cout << pt2 << "+" << sum2 << endl;
    }
    if (sum1 >= p && sum2 >= q)
    {
        int end = min(stk.top(), stk2.top());
        res += end - max(arr_one[pt1 - 1].l, arr_two[pt2 - 1].l) + 1;
        if (stk.top() <= end)
            pt1++;
        else
            pt2++;
        // cout << "yes" << endl;
    }
    cout << res << endl;
}
