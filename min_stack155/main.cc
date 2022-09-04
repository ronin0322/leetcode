/*
 * @Author: ronin0322
 * @Date: 2022-09-04 16:32:03
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-04 16:32:03
 * @FilePath: /leetcode/min_stack155/main.cc
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */

#include <bits/stdc++.h>
using namespace std;

class MinStack
{

private:
    struct Nodes
    {
        int val, index;
    };
    stack<Nodes *> stk;
    stack<Nodes *> minstk;
    int nodeIndex;

public:
    MinStack()
    {
        stk = stack<Nodes *>();
        minstk = stack<Nodes *>();
        nodeIndex = 0;
    }

    void push(int val)
    {
        Nodes *cur = new Nodes{val, nodeIndex++};
        stk.push(cur);
        if (minstk.empty() || minstk.top()->val > cur->val)
        {
            minstk.push(cur);
        }
    }

    void pop()
    {
        auto cur = stk.top();
        stk.pop();
        if (!minstk.empty() && minstk.top()->index == cur->index)
        {
            minstk.pop();
        }
    }

    int top()
    {
        return stk.top()->val;
    }

    int getMin()
    {
        return minstk.top()->val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */