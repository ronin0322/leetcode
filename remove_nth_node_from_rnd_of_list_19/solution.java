/*
 * @Author: ronin0322
 * @Date: 2022-08-11 00:16:16
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-11 00:16:16
 * @FilePath: /leetcode/remove_nth_node_from_rnd_of_list_19/solution.java
 * @Description: 
 * 
 * Copyright (c) 2022 by ronin0322, All Rights Reserved. 
 */
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode prehead = new ListNode();
        prehead.next = head;
        ListNode slow = prehead,fast = prehead ;
        for (int i=0;i<n;i++){
            fast = fast.next;
        }
        for (;fast.next!=null;){
            fast = fast.next;
            slow = slow.next;
        }
        slow.next= slow.next.next;
        return prehead.next;
    }
}