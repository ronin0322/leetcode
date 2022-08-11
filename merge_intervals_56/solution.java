/*
 * @Author: ronin0322
 * @Date: 2022-08-12 01:14:55
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-12 01:14:55
 * @FilePath: /leetcode/merge_intervals_56/solution.java
 * @Description: 
 * 
 * Copyright (c) 2022 by ronin0322, All Rights Reserved. 
 */
class Solution {
    public int[][] merge(int[][] intervals) {
        int n = intervals.length;
        if (n==0 ){
            return new int[0][2];
        }
        Arrays.sort(intervals,new Comparator<int[]>(){
            public int compare(int[] interval1, int[] interval2) {
                return interval1[0] - interval2[0];
            }
        });
        List<int[]> merged = new ArrayList<int[]>();        
        for (int i=0;i<n;i++) {
            int L = intervals[i][0],R=intervals[i][1];
            if (merged.size()==0 ||  merged.get(merged.size()-1)[1] < L ){
                merged.add(new int[]{L,R});
            }else {
                merged.get(merged.size()-1)[1] = Math.max(merged.get(merged.size()-1)[1],R);
            }
        }
        return merged.toArray(new int[merged.size()][]);
    }
}