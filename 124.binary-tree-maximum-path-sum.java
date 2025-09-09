/*
 * @lc app=leetcode id=124 lang=java
 *
 * [124] Binary Tree Maximum Path Sum
 */

import java.util.stream.IntStream;

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
// TODO: 8ms to improve performance
class Solution {
    public int maxPathSum(TreeNode root) {
        PathSum maxPathSum = maxPathSum0(root);
        return Math.max(maxPathSum.singleSideSumWithParent, maxPathSum.otherSum);
    }

    private static PathSum maxPathSum0(TreeNode n) {
        int singleSideSumWithParent = n.val, twoSideSumWithParent = n.val, otherSum = n.val;
        if (n.left != null) {
            final PathSum leftPathSum = maxPathSum0(n.left);
            singleSideSumWithParent = Math.max(singleSideSumWithParent, n.val + leftPathSum.singleSideSumWithParent());
            twoSideSumWithParent += leftPathSum.singleSideSumWithParent();
            otherSum = IntStream.of(otherSum, leftPathSum.otherSum(), leftPathSum.singleSideSumWithParent()).max().getAsInt();
        }
        if (n.right != null) {
            final PathSum rightPathSum = maxPathSum0(n.right);
            singleSideSumWithParent = Math.max(singleSideSumWithParent, n.val + rightPathSum.singleSideSumWithParent());
            twoSideSumWithParent += rightPathSum.singleSideSumWithParent();
            otherSum = IntStream.of(otherSum, rightPathSum.otherSum(), rightPathSum.singleSideSumWithParent()).max().getAsInt();
        }
        return new PathSum(singleSideSumWithParent, Math.max(twoSideSumWithParent, otherSum));
    }

    private static record PathSum(int singleSideSumWithParent, int otherSum) {};
}
// @lc code=end
