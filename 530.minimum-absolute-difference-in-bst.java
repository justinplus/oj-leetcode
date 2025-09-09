/*
 * @lc app=leetcode id=530 lang=java
 *
 * [530] Minimum Absolute Difference in BST
 */

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Iterator;

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
    public int getMinimumDifference(TreeNode root) {
        final InOrderIterator it = new InOrderIterator(root);
        int a = it.next().val, b = it.next().val;
        int minDiff = Math.abs(a - b);
        while(it.hasNext()) {
            a = b;
            b = it.next().val;
            minDiff = Math.min(minDiff, Math.abs(a - b));
        }

        return minDiff;
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
