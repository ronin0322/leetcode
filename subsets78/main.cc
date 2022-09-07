
#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    vector<vector<int>> res;
    int n;

public:
    void dfs(int idx, vector<int> &sets, vector<int> &nums)
    {
        if (idx == n)
        {
            res.push_back(vector<int>(sets.begin(), sets.end()));
            return;
        }
        sets.push_back(nums[idx]);
        dfs(idx + 1, sets, nums);
        sets.pop_back();
        dfs(idx + 1, sets, nums);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        n = nums.size();
        // res = vector<vector<int>>(n+10,vector);
        vector<int> sets;
        dfs(0, sets, nums);
        return res;
    }
};