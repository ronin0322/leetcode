

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int splitArray(vector<int> &nums, int m)
    {
        long long sum = 0;
        for (auto x : nums)
            sum += x;
        long long left = 0, right = sum;
        while (left < right)
        {
            // cout<<left<<" "<<right<<endl;
            long long mid = left + (right - left) / 2;
            if (check(nums, mid, m))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }

    bool check(vector<int> &nums, int subarr_sum, int m)
    {
        int subarr_num = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sum + nums[i] <= subarr_sum)
            {
                sum += nums[i];
            }
            else
            {
                subarr_num++;
                sum = nums[i];
                if (sum > subarr_sum)
                    return false;
            }
        }
        if (sum > 0)
        {
            subarr_num++;
        }
        return subarr_num <= m;
    }
};