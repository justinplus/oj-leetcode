/*
 * @lc app=leetcode id=61 lang=java
 *
 * [61] Rotate List
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
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) {
            return head;
        }
        int len = 1;
        ListNode tail = head;
        for (; tail.next != null; ++len, tail = tail.next);

        final int cnt = len - k % len;
        if (cnt == len) {
            return head;
        }
        ListNode split = head;
        for (int i = 0; i < cnt - 1; ++i) {
            split = split.next;
        }

        tail.next = head;
        final ListNode newHead = split.next;
        split.next = null;

        return newHead;
    }
}
// @lc code=end

