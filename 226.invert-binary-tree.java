/*
 * @lc app=leetcode id=226 lang=java
 *
 * [226] Invert Binary Tree
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
    public TreeNode invertTree(TreeNode root) {
        if (root != null) {
            final TreeNode left = invertTree(root.left);
            final TreeNode right = invertTree(root.right);
            root.left = right;
            root.right = left;
        }

        return root;
    }
}
// @lc code=end
