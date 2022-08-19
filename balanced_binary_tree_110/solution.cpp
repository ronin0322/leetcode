/*
 * @Author: ronin0322
 * @Date: 2022-08-19 10:32:52
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-19 10:33:46
 * @FilePath: /leetcode/balanced_binary_tree_110/solution.cpp
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{

public:
    bool isBalanced(TreeNode *root)
    {
        auto resNode = dfs(root);
        return resNode >= 0 ? true : false;
    }

    int dfs(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        auto lef = dfs(root->left);
        auto rig = dfs(root->right);
        if (lef < 0 || rig < 0)
        {
            return -1;
        }
        if (abs(lef - rig) > 1)
        {
            // cout<<root->val<<resNode.maxV << " "<< resNode.minV<<endl;
            return -1;
        }
        return max(lef, rig) + 1;
    }
};