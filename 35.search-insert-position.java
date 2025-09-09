/*
 * @lc app=leetcode id=35 lang=java
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
    public int searchInsert(int[] nums, int target) {
        int left = 0, right = nums.length;
        while (left < right) {
            final int med = (left + right) / 2;
            final int val = nums[med];
            if (val == target) {
                return med;
            } else if (val < target) {
                left = med + 1;
            } else {
                right = med;
            }
        }
        return target > nums[right] ? right + 1 : right;
    }
}
// @lc code=end
