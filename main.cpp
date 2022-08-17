/*
 * @Author: ronin0322
 * @Date: 2022-08-17 09:22:27
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-17 09:49:00
 * @FilePath: /leetcode/main.cpp
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */

#include <bits/stdc++.h>

using namespace std;

void pri(vector<int> &queue)
{
    for (auto i = queue.begin(); i != queue.end(); i++)
        cout << *i << " " << endl;
}

int main()
{
    cout << "vector" << endl;
    vector<int> queue;
    queue.push_back(0);
    queue.push_back(0);
    queue.push_back(0);
    queue[0] = 1;
    queue[1] = 2;
    queue[2] = 3;
    // queue.push_back(1);
    // queue.push_back(2);
    // queue.push_back(3);
    pri(queue);
    cout << queue.back() << endl;
    queue.pop_back();
    pri(queue);
    cout << "map" << endl;
    unordered_map<int, int> ma;
    ma[1] = 1;
    ma[2] = 2;
    cout << ma[1] << endl;
    cout << ma[2] << endl;
    cout << ma[3] << endl;
    cout << ma[4] << endl;
    for (auto x = ma.begin(); x != ma.end(); x++)
        cout << x->first << " " << x->second << endl;
    cout << ma.size() << endl;

    cout << "stack" << endl;
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    // cout << s.pop() << endl;
    cout << "stack" << endl;
    
    return 0;
}