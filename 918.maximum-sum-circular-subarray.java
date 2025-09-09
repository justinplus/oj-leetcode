/*
 * @lc app=leetcode id=918 lang=java
 *
 * [918] Maximum Sum Circular Subarray
 */

// @lc code=start
class Solution {
    // TODO: find the solution following by leetcode's hint
    public int maxSubarraySumCircular(int[] nums) {
        final int first = nums[0];
        int sum = first, maxEndingHere = first, max = first,
                minEndingHere = first, min = first,
                minEndingHereLen = 1, minSubarrayLen = 1;
        for (int i = 1, len = nums.length; i < len; ++i) {
            final int val = nums[i];
            sum += val;
            if (maxEndingHere > 0) {
                maxEndingHere = maxEndingHere + val;
            } else {
                maxEndingHere = val;
            }
            max = Math.max(max, maxEndingHere);
            if (minEndingHere < 0) {
                minEndingHere = minEndingHere + val;
                ++minEndingHereLen;
            } else {
                minEndingHere = val;
                minEndingHereLen = 1;
            }
            if (minEndingHere < min) {
                min = minEndingHere;
                minSubarrayLen = minEndingHereLen;
            }
        }
        return minSubarrayLen == nums.length ? max : Math.max(max, sum - min);
    }
}
// @lc code=end
