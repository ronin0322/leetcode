/*
 * @Author: ronin0322
 * @Date: 2022-09-03 22:18:18
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-09-03 22:18:19
 * @FilePath: /leetcode/reverse_words_in_a_string_151/main.cpp
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */


#include<bits/stdc++.h>

using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());
        int last = 0;
        // cout<<s<<endl;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
                continue;
            reverse(s.begin() + last, s.begin() + i);
            last = i + 1;
        }
        reverse(s.begin() + last, s.end());
        // cout<<s<<endl;
        int idx = 0;
        int end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
                continue;
            if (idx != 0)
                s[idx++] = ' ';
            while (i < s.size() && s[i] != ' ')
            {
                s[idx] = s[i];
                idx++;
                i++;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};