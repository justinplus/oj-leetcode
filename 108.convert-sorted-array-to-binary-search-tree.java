/*
 * @lc app=leetcode id=108 lang=java
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */

// @lc code=start
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

class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        return sortedArrayToBST(nums, 0, nums.length - 1);
    }

    private static TreeNode sortedArrayToBST(int[] nums, int left, int right) {
        final int med = (left + right) / 2;
        final TreeNode n = new TreeNode(nums[med]);
        if (med - left > 0) {
            n.left = sortedArrayToBST(nums, left, med - 1);
        }
        if (right - med > 0) {
            n.right = sortedArrayToBST(nums, med + 1, right);
        }
        return n;
    }
}
// @lc code=end
