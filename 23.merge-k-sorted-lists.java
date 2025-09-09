/*
 * @lc app=leetcode id=23 lang=java
 *
 * [23] Merge k Sorted Lists
 */

import java.util.Comparator;
import java.util.PriorityQueue;

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
    // TODO: 6ms, beats 29.56%. Improve performance
    public ListNode mergeKLists(ListNode[] lists) {
        // TODO: implement the priority queue
        final PriorityQueue<ListNode> q = new PriorityQueue<>(Math.max(16, lists.length), Comparator.comparingInt(node -> node.val));
        for (ListNode l : lists) {
            if (l != null) {
                q.offer(l);
            }
        }

        final ListNode dummy = new ListNode();
        ListNode l = dummy;
        while (!q.isEmpty()) {
            final ListNode n = q.poll();
            l.next = n;
            l = l.next;
            if (n.next != null) {
                q.offer(n.next);
            }
        }

        return dummy.next;
    }
}
// @lc code=end
