/*
 * @lc app=leetcode id=222 lang=java
 *
 * [222] Count Complete Tree Nodes
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
    public int countNodes(TreeNode root) {
        return countNodesByBinarySearch(root);
    }

    public int countNodesByDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int depthLeft = 1;
        for (TreeNode n = root.left; n != null; ++depthLeft, n = n.left);
        int depthRight = 1;
        for (TreeNode n = root.right; n != null; ++depthRight, n = n.right);

        if (depthLeft == depthRight) {
            int cnt = 1;
            for (int i = 0; i < depthLeft; ++i) {
                cnt *= 2;
            }
            return cnt - 1;
        }
        
        return 1 + countNodesByDepth(root.left) + countNodesByDepth(root.right);
    }

    public int countNodesByBinarySearch(TreeNode root) {
        int depthLeft = 0;
        for (TreeNode n = root; n != null; ++depthLeft, n = n.left);

        if (depthLeft == 0) {
            return 0;
        }

        int cntOfLastLevel = 1;
        for (int i = 0; i < depthLeft - 1; ++i) {
            cntOfLastLevel *= 2;
        }

        int left = 0, right = cntOfLastLevel - 1;
        while (left < right - 1) {
            final int med = (left + right) / 2;
            if (isNull(root, med, depthLeft)) {
                right = med;
            } else {
                left = med;
            }
        }

        return isNull(root, right, depthLeft) ? cntOfLastLevel + right - 1 : cntOfLastLevel + right;
    }

    private static boolean isNull(TreeNode node, int index, int depth) {
        for (int i = depth - 2; i >= 0; --i) {
            if (isRight(index, i)) {
                node = node.right;
            } else {
                node = node.left;
            }
        }
        
        return node == null;
    }
    private static boolean isRight(int index, int pos) {
        int mask = 1 << pos;
        return (index & mask) > 0;
    }
}
// @lc code=end
