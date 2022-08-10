/*
 * @Author: ronin0322
 * @Date: 2022-08-11 01:44:16
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-11 01:44:17
 * @FilePath: /leetcode/generate_parentheses_22/solution.java
 * @Description: 
 * 
 * Copyright (c) 2022 by ronin0322, All Rights Reserved. 
 */
class Solution {
    List[] cache = new ArrayList[100] ;
    public List<String> generate(int n){
        if (cache[n]!=null) {
            return cache[n];
        }
        List<String> ans = new ArrayList<String>();
        if (n== 0) {
            ans.add("");
        }else {
            for (int k=0;k<n;k++){
                for (String x:generate(k)){
                    for (String y:generate(n-k-1)){
                        ans.add("("+x+")"+y);
                    }
                }
            }
        }
        cache[n] = ans;
        return ans;
    }

    public List<String> generateParenthesis(int n) {
        return generate(n);
    }
}