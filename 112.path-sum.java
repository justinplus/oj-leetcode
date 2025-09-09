/*
 * @lc app=leetcode id=112 lang=java
 *
 * [112] Path Sum
 */

import java.util.ArrayDeque;
import java.util.Deque;

// Definition for a binary tree node.
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
    public boolean hasPathSum(TreeNode root, int targetSum) {
        return hasPathSumIterative(root, targetSum);
    }

    // 0ms
    public boolean hasPathSumRecursive(TreeNode root, int targetSum) {
        return root != null && hasPathSumRecursive0(root, targetSum);
    }

    private static boolean hasPathSumRecursive0(TreeNode root, int targetSum) {
        return root.left == null && root.right == null && root.val == targetSum
                || root.left != null && hasPathSumRecursive0(root.left, targetSum - root.val)
                || root.right != null && hasPathSumRecursive0(root.right, targetSum - root.val);
    }

    // TODO: 1ms, why non-recursive is slower
    public boolean hasPathSumIterative(TreeNode root, int targetSum) {
        if (root == null) {
            return false;
        }
        final Deque<TreeNode> stack = new ArrayDeque<>(100);
        int sum = 0;
        for (TreeNode n = root; n != null; n = n.left == null ? n.right : n.left) {
            stack.addLast(n);
            sum += n.val;
        }

        if (sum == targetSum) {
            return true;
        }
        while (!stack.isEmpty()) {
            final TreeNode node = stack.removeLast();
            sum -= node.val;

            final TreeNode parent = stack.peekLast();
            if (parent != null && parent.left == node) {
                if (parent.right != null) {
                    for (TreeNode n = parent.right; n != null; n = n.left == null ? n.right : n.left) {
                        stack.addLast(n);
                        sum += n.val;
                    }
                    if (sum == targetSum) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}
// @lc code=end
