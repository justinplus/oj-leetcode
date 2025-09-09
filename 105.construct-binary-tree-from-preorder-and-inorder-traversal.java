/*
 * @lc app=leetcode id=105 lang=java
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    // TODO: Build a hashmap of value → index for the inorder array
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return buildTree(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1);
    }

    private static TreeNode buildTree(int[] preorder, int l1, int r1, int[] inorder, int l2, int r2) {
        if (l1 == r1) {
            return new TreeNode(preorder[l1]);
        }

        final TreeNode parent = new TreeNode(preorder[l1]);
        int i = l2;
        for (int val = parent.val; inorder[i] != val; ++i);
        parent.left = l2 <= i - 1 ? buildTree(preorder, l1 + 1, l1 + i - l2, inorder, l2, i - 1) : null;
        parent.right = i + 1 <= r2 ? buildTree(preorder, l1 + i - l2 + 1, r1, inorder, i + 1, r2) : null;

        return parent;
    }
}
// @lc code=end
