/*
 * @lc app=leetcode id=117 lang=java
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

import java.util.ArrayDeque;
import java.util.Deque;

// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

// @lc code=start
class Solution {
    public Node connect(Node root) {
        Deque<Node> q1 = new ArrayDeque<>();
        Deque<Node> q2 = new ArrayDeque<>();
        if (root != null) {
            q1.addLast(root);
        }

        while (!q1.isEmpty()) {
            do {
                final Node n1 = q1.removeFirst();
                if (n1.left != null) {
                    final Node n2 = q2.peekLast();
                    q2.addLast(n1.left);
                    if (n2 != null) {
                        n2.next = n1.left;
                    }
                }
                if (n1.right != null) {
                    final Node n2 = q2.peekLast();
                    q2.addLast(n1.right);
                    if (n2 != null) {
                        n2.next = n1.right;
                    }
                }
            } while (!q1.isEmpty());

            final Deque<Node> q = q1;
            q1 = q2;
            q2 = q;

        }

        return root;
    }
}
// @lc code=end

