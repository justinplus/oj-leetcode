/*
 * @lc app=leetcode id=153 lang=java
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
    public int findMin(int[] nums) {
        int left = 0, right = nums.length - 1;
        while (left < right) {
            if (nums[left] < nums[right]) {
                return nums[left];
            }

            final int med = (left + right) / 2;
            if (nums[left] > nums[med]) {
                right = med;
            } else {
                left = med + 1;
            }
        }
        return nums[left];
    }
}
// @lc code=end

