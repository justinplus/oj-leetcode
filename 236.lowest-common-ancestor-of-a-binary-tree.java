/*
 * @lc app=leetcode id=236 lang=java
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// Definition for a binary tree node.

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Deque;
import java.util.Iterator;
import java.util.List;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

// @lc code=start
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        final PostOrderIterator it = new PostOrderIterator(root);
        final List<TreeNode> pathP = new ArrayList<>();
        final List<TreeNode> pathQ = new ArrayList<>();
        for (TreeNode n = it.peekNext(); n != null; it.next(), n = it.peekNext()) {
            if (!pathP.isEmpty() && !pathQ.isEmpty()) {
                break;
            }
            if (n == p) {
                pathP.addAll(it.getPath());
            }
            if (n == q) {
                pathQ.addAll(it.getPath());
            }
        }

        int i = 0;
        for (int len = Math.min(pathP.size(), pathQ.size()); i < len; ++i) {
            if (pathP.get(i) != pathQ.get(i)) {
                break;
            }
        }

        assert i >= 1;
        return pathP.get(i - 1);
    }

    private static class PostOrderIterator implements Iterator<TreeNode> {
        private final Deque<TreeNode> stack;

        public PostOrderIterator(TreeNode root) {
            this.stack = new ArrayDeque<>(512);
            for (TreeNode n = root; n != null; stack.addLast(n), n = n.left == null ? n.right : n.left);
        }

        public Collection<TreeNode> getPath() {
            return Collections.unmodifiableCollection(stack);
        }

        public TreeNode peekNext() {
            return stack.peekLast();
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
            final TreeNode parent = stack.peekLast();
            if (parent != null && node == parent.left) {
                for (TreeNode n = parent.right; n != null; stack.addLast(n), n = n.left == null ? n.right : n.left);
            }

            return node;
        }
    }
}
// @lc code=end

