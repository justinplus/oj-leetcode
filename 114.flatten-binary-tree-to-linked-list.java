/*
 * @lc app=leetcode id=114 lang=java
 *
 * [114] Flatten Binary Tree to Linked List
 */

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
    public void flatten(TreeNode root) {
        if (root != null) {
            flattern0(root);
        }
    }

    private static TreeNode flattern0(TreeNode node) {
        final TreeNode leftHead = node.left;
        final TreeNode leftTail = node.left == null ? null : flattern0(node.left);
        final TreeNode rightHead = node.right;
        final TreeNode rightTail = node.right == null ? null : flattern0(node.right);

        if (leftHead != null) {
            node.right = leftHead;
            leftTail.right = rightHead;
        }
        node.left = null;
        return rightHead == null ? (leftHead == null ? node : leftTail) : rightTail;
    }
}
// @lc code=end
