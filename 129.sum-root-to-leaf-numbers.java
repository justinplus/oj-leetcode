/*
 * @lc app=leetcode id=129 lang=java
 *
 * [129] Sum Root to Leaf Numbers
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
    public int sumNumbers(TreeNode root) {
        return sumNumbers(root, 0);
    }

    private static int sumNumbers(TreeNode node, int partialNum) {
        final int num = partialNum * 10 + node.val;
        if (node.left == null && node.right == null) {
            return num;
        }
        int sum = 0;
        if (node.left != null) {
            sum += sumNumbers(node.left, num);
        }
        if (node.right != null) {
            sum += sumNumbers(node.right, num);
        }

        return sum;
    }
}
// @lc code=end
