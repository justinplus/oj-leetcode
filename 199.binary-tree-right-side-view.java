/*
 * @lc app=leetcode id=199 lang=java
 *
 * [199] Binary Tree Right Side View
 */

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;


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
    public List<Integer> rightSideView(TreeNode root) {
        Deque<TreeNode> q1 = new ArrayDeque<>(64);
        Deque<TreeNode> q2 = new ArrayDeque<>(64);

        List<Integer> result = new ArrayList<>();
        if (root != null) {
            q1.addLast(root);
        }
        while (!q1.isEmpty()) {
            TreeNode n = q1.removeFirst();
            result.add(n.val);
            if (n.right != null) {
                q2.add(n.right);
            }
            if (n.left != null) {
                q2.add(n.left);
            }

            while (!q1.isEmpty()) {
                n = q1.removeFirst();
                if (n.right != null) {
                    q2.add(n.right);
                }
                if (n.left != null) {
                    q2.add(n.left);
                }
            }

            final Deque<TreeNode> q = q1;
            q1 = q2;
            q2 = q;
        }

        return result;
    }
}
// @lc code=end
