/*
 * @lc app=leetcode id=106 lang=java
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    // TODO: Build a hashmap of value → index for the inorder array
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return buildTree(inorder, 0, inorder.length - 1, postorder, 0, postorder.length - 1);
        
    }

    public TreeNode buildTree(int[] inorder, int l1, int r1, int[] postorder, int l2, int r2) {
        if (l1 == r1) {
            return new TreeNode(inorder[l1]);
        }

        final TreeNode parent = new TreeNode(postorder[r2]);
        int i = l1;
        for (int val = parent.val; inorder[i] != val; ++i);
        parent.left = l1 <= i - 1 ? buildTree(inorder, l1, i - 1, postorder, l2, l2 + i - l1 - 1) : null;
        parent.right = i + 1 <= r1 ? buildTree(inorder, i + 1, r1, postorder, l2 + i - l1, r2 - 1) : null;
        return parent;
    }
}
// @lc code=end

