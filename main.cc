/*
 * @Author: ronin0322
 * @Date: 2022-09-10 15:41:53
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-14 15:52:01
 * @FilePath: /leetcode/main.cc
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Channel
{
public:
    Channel() : cap_(0)
    {
    }
    Channel(int cap) : cap_(cap)
    {
    }
    void ToString()
    {
        cout << "hh" << endl;
        for (auto x : data_)
            cout << x << " ";
        cout << endl;
    }
    void operator<<(T val)
    {
        if (mutex_.try_lock())
        {
            data_.push(val);
            mutex_.unlock();
        }
    }

    T Read()
    {
        T res;
        if (mutex_.try_lock())
        {
            res = data_.front();
            data_.pop();
            mutex_.unlock();
            return res;
        }
        return res;
    }

private:
    mutex mutex_;
    queue<T> data_;
    int cap_;
};

vector<vector<int>> res;
void add(vector<int> &path)
{
    res.push_back(path);
}

int main()
{
    Channel<int> ch(1);
    ch << 2;
    cout << ch.Read() << endl;
    return 0;
}
