/*
 * @lc app=leetcode id=2 lang=java
 *
 * [2] Add Two Numbers
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        final ListNode dummy = new ListNode(0);
        ListNode node = dummy;
        int carry = 0;
        while (l1 != null && l2 != null) {
            int sum = l1.val + l2.val + carry;
            carry = sum / 10;
            node.next = new ListNode(sum % 10);
            node = node.next;
            l1 = l1.next;
            l2 = l2.next;
        }

        ListNode remained = l1 == null ? l2 : l1;
        while (remained != null) {
            int sum = remained.val + carry;
            carry = sum / 10;
            node.next = new ListNode(sum % 10);
            node = node.next;
            remained = remained.next;
        }

        if (carry != 0) {
            node.next = new ListNode(carry);
        }

        return dummy.next;
    }
}
// @lc code=end

