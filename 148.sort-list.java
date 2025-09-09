/*
 * @lc app=leetcode id=148 lang=java
 *
 * [148] Sort List
 */

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

// @lc code=start
class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        // NOTE: no need to use dummy node here. Improve from 12ms to 9ms
        // Tip: fast should be the next of the head
        ListNode slow = head, fast = head.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        final ListNode med = slow.next;
        slow.next = null;
        return merge(sortList(head), sortList(med));
    }

    private static ListNode merge(ListNode l1, ListNode l2) {
        final ListNode dummy = new ListNode();
        ListNode h = dummy;
        for (; l1 != null && l2 != null; h = h.next) {
            if (l1.val <= l2.val) {
                h.next = l1;
                l1 = l1.next;
            } else {
                h.next = l2;
                l2 = l2.next;
            }
        }

        h.next = l1 == null ? l2 : l1;
        return dummy.next;
    }
}
// @lc code=end
