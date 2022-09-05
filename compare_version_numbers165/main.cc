

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> toNum(string s)
    {
        vector<int> res;
        int num = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '.')
                num = num * 10 + (s[i] - '0');
            else
            {
                res.push_back(num);
                num = 0;
            }
        }
        if (num > 0)
            res.push_back(num);
        return res;
    }
    int compareVersion(string version1, string version2)
    {
        auto nums1 = toNum(version1);
        auto nums2 = toNum(version2);
        for (int i = 0; i < nums1.size() || i < nums2.size(); i++)
        {
            int num1 = i < nums1.size() ? nums1[i] : 0;
            int num2 = i < nums2.size() ? nums2[i] : 0;
            if (num1 < num2)
                return -1;
            else if (num1 > num2)
                return 1;
        }
        return 0;
    }
};