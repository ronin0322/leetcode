/*
 * @Author: ronin0322
 * @Date: 2022-09-04 15:11:59
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-04 15:11:59
 * @FilePath: /leetcode/construct_binary_tree_from_preorder_and_inorder_traversal105/main.cc
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (!preorder.size())
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode{preorder[0]};
        stack<TreeNode *> stk;
        stk.push(root);
        int inorderIndex = 0;
        for (int i = 1; i < preorder.size(); i++)
        {
            int preorderVal = preorder[i];
            TreeNode *node = stk.top();
            if (node->val != inorder[inorderIndex])
            {
                node->left = new TreeNode{preorderVal};
                stk.push(node->left);
            }
            else
            {
                while (!stk.empty() && stk.top()->val == inorder[inorderIndex])
                {
                    node = stk.top();
                    stk.pop();
                    inorderIndex++;
                }
                node->right = new TreeNode{preorderVal};
                stk.push(node->right);
            }
        }
        return root;
    }
};