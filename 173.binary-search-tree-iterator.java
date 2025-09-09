/*
 * @lc app=leetcode id=173 lang=java
 *
 * [173] Binary Search Tree Iterator
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
class BSTIterator {
    private final Deque<TreeNode> stack;

    public BSTIterator(TreeNode root) {
        // 17ms
        // this.stack = new LinkedList<>(128);
        // 16ms
        this.stack = new ArrayDeque<>(128);
        for (TreeNode n = root; n != null; stack.addLast(n), n = n.left);
    }

    public int next() {
        final TreeNode node = stack.removeLast();
        for (TreeNode n = node.right; n != null; stack.addLast(n), n = n.left);
        return node.val;
    }

    public boolean hasNext() {
        return !stack.isEmpty();
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
// @lc code=end
