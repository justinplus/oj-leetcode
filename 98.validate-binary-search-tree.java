/*
 * @lc app=leetcode id=98 lang=java
 *
 * [98] Validate Binary Search Tree
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
    public boolean isValidBST(TreeNode root) {
        return null != getMinMaxIfValidBST(root);
    }

    private static MinMax getMinMaxIfValidBST(TreeNode root) {
        int min = root.val, max = root.val;
        if (root.left != null) {
            final MinMax leftMinMax = getMinMaxIfValidBST(root.left);
            if (leftMinMax == null || root.val <= leftMinMax.max()) {
                return null;
            }
            min = leftMinMax.min();
        }
        if (root.right != null) {
            final MinMax rightMinMax = getMinMaxIfValidBST(root.right);
            if (rightMinMax == null || root.val >= rightMinMax.min()) {
                return null;
            }
            max = rightMinMax.max();
        }
        return new MinMax(min, max);
    }

    private static record MinMax(int min, int max) {};
}
// @lc code=end
