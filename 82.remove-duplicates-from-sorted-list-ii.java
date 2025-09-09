/*
 * @lc app=leetcode id=82 lang=java
 *
 * [82] Remove Duplicates from Sorted List II
 */

// @lc code=start
// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        final ListNode dummy = new ListNode(0, head);
        ListNode pre = dummy;

        while (pre.next != null) {
            ListNode n = pre.next.next;
            if (n != null && n.val == pre.next.val) {
                do {
                    n = n.next;
                } while (n != null && n.val == pre.next.val);
                pre.next = n;
            } else {
                pre = pre.next;
            }
        }

        return dummy.next;
    }
}
// @lc code=end
