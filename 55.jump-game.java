/*
 * @lc app=leetcode id=55 lang=java
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
    public boolean canJump(int[] nums) {
        final int len = nums.length;
        int farthestIndex = 0;
        for (int i = 0; i <= farthestIndex && i < len; ++i) {
            farthestIndex = Math.max(farthestIndex, i + nums[i]);
            if (farthestIndex >= len - 1) {
                return true;
            }
        }
        return false;
    }
}
// @lc code=end
