/*
 * @lc app=leetcode id=70 lang=java
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
    public int climbStairs(int n) {
        int pre2 = 1;
        int pre1 = 1;
        while (--n > 0) {
            final int curr = pre1 + pre2;
            pre2 = pre1;
            pre1 = curr;
        }

        return pre1;
    }
}
// @lc code=end

