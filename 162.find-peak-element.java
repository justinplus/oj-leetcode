/*
 * @lc app=leetcode id=162 lang=java
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
    public int findPeakElement(int[] nums) {
        final int len = nums.length;
        if (len == 1) {
            return 0;
        }
        if (nums[0] > nums[1]) {
            return 0;
        }
        if (nums[len - 1] > nums[len - 2]) {
            return len - 1;
        }

        int left = 0, right = nums.length - 1;
        while (left < right) {
            final int med = (left + right) / 2;
            final int val = nums[med];

            if (val < nums[med - 1]) {
                right = med;
            } else if (val < nums[med + 1]) {
                left = med;
            } else {
                return med;
            }
        }
        throw new AssertionError("Should never arrive here");
    }
}
// @lc code=end
