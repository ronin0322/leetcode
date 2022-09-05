/*
 * @Author: ronin0322
 * @Date: 2022-09-05 10:51:15
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-05 10:51:15
 * @FilePath: /leetcode/sum_root_to_leaf_numbers129/main.cc
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <bits/stdc++.h>

using namespace std;
class Solution
{
private:
    int res;

public:
    void dfs(TreeNode *root, int sum)
    {
        if (!root)
        {
            return;
        }
        int newSum = sum * 10 + root->val;
        if (!root->left && !root->right)
            res += newSum;
        else
        {
            dfs(root->left, newSum);
            dfs(root->right, newSum);
        }
    }

    int sumNumbers(TreeNode *root)
    {
        res = 0;
        dfs(root, 0);
        return res;
    }
};