/*
 * @lc app=leetcode id=25 lang=java
 *
 * [25] Reverse Nodes in k-Group
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
    public static ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || k <= 1) {
            return head;
        }

        Holder<ListNode> nextGroupHolder = new Holder<>(head);
        if (!proceedToNextGroup(nextGroupHolder, k)) {
            return head;
        }
        ListNode pre = head, curr = head.next;
        for (int i = 0; i < k - 1; ++i) {
            final ListNode next = curr.next;
            curr.next = pre;
            pre = curr;
            curr = next;
        }

        final ListNode newHead = pre;
        ListNode preGroup = head, currGroup = nextGroupHolder.get();
        while (proceedToNextGroup(nextGroupHolder, k)) {
            pre = currGroup;
            curr = currGroup.next;
            for (int i = 0; i < k - 1; ++i) {
                final ListNode next = curr.next;
                curr.next = pre;
                pre = curr;
                curr = next;
            }
            preGroup.next = pre;
            preGroup = currGroup;
            currGroup = nextGroupHolder.get();
        }
        preGroup.next = currGroup;
        return newHead;
    }

    private static boolean proceedToNextGroup(Holder<ListNode> nodeHolder, int k) {
        int i = 0;
        ListNode node = nodeHolder.get();
        for (; i < k & node != null; ++i, node = node.next);
        nodeHolder.set(node);
        return i == k;
    }

    private static class Holder<T> {
        private T value;

        public Holder(T value) {
            this.value = value;
        }

        public T get() {
            return value;
        }

        public void set(T v) {
            this.value = v;
        }
    }
}
// @lc code=end
