/*
 * @lc app=leetcode id=637 lang=java
 *
 * [637] Average of Levels in Binary Tree
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
    public List<Double> averageOfLevels(TreeNode root) {
        Deque<TreeNode> stack1 = new ArrayDeque<>();
        Deque<TreeNode> stack2 = new ArrayDeque<>();

        stack1.addLast(root);
        final List<Double> result = new ArrayList<>();
        while (!stack1.isEmpty()) {
            // NOTE: note the range of the value
            long sum = 0;
            int cnt = 0;
            do {
                final TreeNode n = stack1.removeLast();
                sum += n.val;
                ++cnt;
                if (n.left != null) {
                    stack2.addLast(n.left);
                }
                if (n.right != null) {
                    stack2.addLast(n.right);
                }
            } while (!stack1.isEmpty());
            result.add(((double) sum) / cnt);

            final Deque<TreeNode> s = stack2;
            stack2 = stack1;
            stack1 = s;
        }
        return result;
    }
}
// @lc code=end
