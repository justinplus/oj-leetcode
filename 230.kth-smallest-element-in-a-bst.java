/*
 * @lc app=leetcode id=230 lang=java
 *
 * [230] Kth Smallest Element in a BST
 */

// Definition for a binary tree node.

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Iterator;

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
    public int kthSmallest(TreeNode root, int k) {
        final InOrderIterator it = new InOrderIterator(root);
        TreeNode n = null;
        for (int i = 0; i < k; ++i) {
            n = it.next();
        }
        return n.val;
    }

    private static class InOrderIterator implements Iterator<TreeNode> {
        private final Deque<TreeNode> stack;
        public InOrderIterator(TreeNode root) {
            this.stack = new ArrayDeque<>(512);
            for (TreeNode n = root; n != null; stack.addLast(n), n = n.left);
        }

        @Override
        public boolean hasNext() {
            return !stack.isEmpty();
        }

        @Override
        public TreeNode next() {
            if (stack.isEmpty()) {
                return null;
            }

            final TreeNode node = stack.removeLast();
            for (TreeNode n = node.right; n != null; stack.addLast(n), n = n.left);
            return node;
        }
    }
}
// @lc code=end
