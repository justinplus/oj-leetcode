/*
 * @lc app=leetcode id=104 lang=java
 *
 * [104] Maximum Depth of Binary Tree
 */

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.LinkedList;

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
    public int maxDepth(TreeNode root) {
        return maxDepthPostOrder(root);
    }

    // 1 ms
    public int maxDepthLevelOrder(TreeNode root) {
        Deque<TreeNode> q1 = new LinkedList<>();
        Deque<TreeNode> q2 = new LinkedList<>();

        if (root != null) {
            q1.addLast(root);
        }
        int level = 0;
        while (!q1.isEmpty()) {
            do {
                final TreeNode n = q1.pollFirst();
                if (n.left != null) {
                    q2.addLast(n.left);
                }
                if (n.right != null) {
                    q2.addLast(n.right);
                }
            } while (!q1.isEmpty());
            ++level;
            final Deque<TreeNode> tmp = q1;
            q1 = q2;
            q2 = tmp;
        }

        return level;
    }

    // 0 ms
    public int maxDepthPostOrder(TreeNode root) {
        if (root == null) {
            return 0;
        } else {
            final int depthLeft = root.left == null ? 0 : maxDepthPostOrder(root.left);
            final int depthRight = root.right == null ? 0 : maxDepthPostOrder(root.right);
            return Math.max(depthLeft, depthRight) + 1;
        }
    }

    // TODO: Why non recursive version is slower? - 2 ms
    public int maxDepthPostOrderNonRecursive(TreeNode root) {
        final Deque<TreeNode> stack = new ArrayDeque<>(128);
        for (TreeNode n = root; n != null; stack.addLast(n), n = n.left == null ? n.right : n.left);

        int maxDepth = stack.size();
        while (!stack.isEmpty()) {
            final TreeNode node = stack.removeLast();
            // visit node
            final TreeNode parent = stack.peekLast();
            if (parent != null && node == parent.left) {
                for (TreeNode n = parent.right; n != null; stack.addLast(n), n = n.left == null ? n.right : n.left);
            }
            maxDepth = Math.max(maxDepth, stack.size());
        }
        return maxDepth;
    }
}
// @lc code=end
