/*
 * @lc app=leetcode id=92 lang=java
 *
 * [92] Reverse Linked List II
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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        final ListNode dummy = new ListNode(0, head);
        ListNode pre = dummy;
        for (int i = 1; i < left; ++i) {
            pre = pre.next;
        }
        ListNode curr = pre.next;
        ListNode next = curr.next;
        if (next == null) {
            return head;
        }

        for (int i = left; i < right; ++i) {
            final ListNode next2 = next.next;
            next.next = curr;
            curr = next;
            next = next2;
        }

        pre.next.next = next;
        pre.next = curr;

        return dummy.next;
    }
}
// @lc code=end
