/*
 * @lc app=leetcode id=86 lang=java
 *
 * [86] Partition List
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
    public ListNode partition(ListNode head, int x) {
        final ListNode dummyHead1 = new ListNode(), dummyHead2 = new ListNode();
        ListNode l1 = dummyHead1, l2 = dummyHead2;
        for (ListNode n = head; n != null; n = n.next) {
            if (n.val < x) {
                l1.next = n;
                l1 = l1.next;
            } else {
                l2.next = n;
                l2 = l2.next;
            }
        }
        l1.next = dummyHead2.next;
        l2.next = null;
        return dummyHead1.next;
    }
}
// @lc code=end
