/*
 * @lc app=leetcode id=103 lang=java
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 */

// Definition for a binary tree node.

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

// @lc code=start
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        final TreeNode DELIMITER = new TreeNode();
        final Deque<TreeNode> queue = new ArrayDeque<>(500);
        if (root != null) {
            queue.addLast(root);
            queue.addLast(DELIMITER);
        }

        final List<List<Integer>> result = new ArrayList<>();
        int iterations = 1;
        List<Integer> values = new ArrayList<>();
        while (!queue.isEmpty()) {
            final TreeNode n = iterations % 2 == 0 ? queue.removeLast() : queue.removeFirst();
            if (n == DELIMITER) {
                result.add(values);
                if (!queue.isEmpty()) {
                    ++iterations;
                    if (iterations % 2 == 0) {
                        queue.addFirst(n);
                    } else {
                        queue.addLast(n);
                    }
                    values = new ArrayList<>();
                }
            } else {
                values.add(n.val);
                if (iterations % 2 == 0) {
                    if (n.right != null) {
                        queue.addFirst(n.right);
                    }
                    if (n.left != null) {
                        queue.addFirst(n.left);
                    }
                } else {
                    if (n.left != null) {
                        queue.addLast(n.left);
                    }
                    if (n.right != null) {
                        queue.addLast(n.right);
                    }
                }
            }
        }
        return result;
    }
}
// @lc code=end
