/*
 * @lc app=leetcode id=102 lang=java
 *
 * [102] Binary Tree Level Order Traversal
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
    public List<List<Integer>> levelOrder(TreeNode root) {
        final TreeNode DELIMITER = new TreeNode();
        final Deque<TreeNode> queue = new ArrayDeque<>(500);
        if (root != null) {
            queue.addLast(root);
            queue.addLast(DELIMITER);
        }

        final List<List<Integer>> result = new ArrayList<>();
        List<Integer> values = new ArrayList<>();
        while (!queue.isEmpty()) {
            TreeNode n = queue.removeFirst();
            if (n == DELIMITER) {
                result.add(values);
                if (!queue.isEmpty()) {
                    queue.addLast(n);
                    values = new ArrayList<>();
                }
            } else {
                values.add(n.val);
                if (n.left != null) {
                    queue.add(n.left);
                }
                if (n.right != null) {
                    queue.add(n.right);
                }
            }
        }
        return result;
    }
}
// @lc code=end
