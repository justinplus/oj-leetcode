/*
 * @lc app=leetcode id=101 lang=java
 *
 * [101] Symmetric Tree
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
    public boolean isSymmetric(TreeNode root) {
        return isSymmetricIterative(root);
    }

    // 0ms
    public static boolean isSymmetricRecursive(TreeNode root) {
        return root == null || isSymmetricRecursive(root.left, root.right);
    }

    private static boolean isSymmetricRecursive(TreeNode n1, TreeNode n2) {
        if (n1 == null && n2 == null) {
            return true;
        } else if (n1 != null && n2 != null && n1.val == n2.val) {
            return isSymmetricRecursive(n1.left, n2.right) && isSymmetricRecursive(n1.right, n2.left);
        } else {
            return false;
        }
    }

    // TODO: 1ms why non-recursive is slower
    // NOTE: null child should be compared
    private static boolean isSymmetricIterative(TreeNode root) {
        if (root == null) {
            return true;
        }

        final PreOrderIterator leftIt = new PreOrderIterator(root.left, false);
        final PreOrderIterator rightIt = new PreOrderIterator(root.right, true);
        while (leftIt.hasNext() && rightIt.hasNext()) {
            final TreeNode nextLeft = leftIt.next();
            final TreeNode nextRight = rightIt.next();
            if (nextLeft == PreOrderIterator.NULL_NODE && nextRight != PreOrderIterator.NULL_NODE
                    || nextLeft != PreOrderIterator.NULL_NODE && nextRight == PreOrderIterator.NULL_NODE
                    || nextLeft.val != nextRight.val) {
                return false;
            }
        }
        return leftIt.hasNext() == rightIt.hasNext();
    }

    private static class PreOrderIterator implements Iterator<TreeNode> {
        public static final TreeNode NULL_NODE = new TreeNode();
        private final Deque<TreeNode> stack = new ArrayDeque<>();
        private final boolean rightChildFirst;

        public PreOrderIterator(TreeNode root, boolean rightChildFirst) {
            if (root != null) {
                this.stack.addLast(root);
            }
            this.rightChildFirst = rightChildFirst;
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

            TreeNode n = stack.removeLast();
            if (n == NULL_NODE) {
                return n;
            }
            if (rightChildFirst) {
                if (n.left != null) {
                    stack.addLast(n.left);
                } else {
                    stack.addLast(NULL_NODE);
                }
                if (n.right != null) {
                    stack.addLast(n.right);
                } else {
                    stack.addLast(NULL_NODE);
                }
            } else {
                if (n.right != null) {
                    stack.addLast(n.right);
                } else {
                    stack.addLast(NULL_NODE);
                }
                if (n.left != null) {
                    stack.addLast(n.left);
                } else {
                    stack.addLast(NULL_NODE);
                }
            }
            return n;
        }
    }
}
// @lc code=end
