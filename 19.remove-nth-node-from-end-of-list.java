/*
 * @lc app=leetcode id=19 lang=java
 *
 * [19] Remove Nth Node From End of List
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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        final ListNode dummy = new ListNode(0, head);
        ListNode n1 = dummy, n2 = dummy;
        for (int i = 0; i < n; ++i) {
            n1 = n1.next;
        }
        while (n1.next != null) {
            n1 = n1.next;
            n2 = n2.next;
        }
        n2.next = n2.next.next;

        return dummy.next;
    }
}
// @lc code=end
