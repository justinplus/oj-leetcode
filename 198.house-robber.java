/*
 * @lc app=leetcode id=198 lang=java
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
    /*
     * f(i) is the max amount can rob without alerting the police.
     * g(i) is the max amount can rob if i is robbed
     * 
     * f(i) = max( g(1), g(i - 1) )
     * g(i) = max( g(i - 1), g(i - 2)) + nums[i]
     */
    public int rob(int[] nums) {
        int g1 = 0, g2 = 0, g3 = nums[0];
        for (int i = 1, len = nums.length; i < len; ++i) {
            final int g4 = Math.max(g2, g1) + nums[i];
            g1 = g2;
            g2 = g3;
            g3 = g4;
        }

        return Math.max(g2, g3);
    }
}
// @lc code=end

