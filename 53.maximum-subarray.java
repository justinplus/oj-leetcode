/*
 * @lc app=leetcode id=53 lang=java
 *
 * [53] Maximum Subarray
 */

import java.util.stream.IntStream;

// @lc code=start
class Solution {
    public int maxSubArray(int[] nums) {
        return maxSubArrayDC(nums);
    }

    // 1ms bests 99.51%
    public static int maxSubArrayDP(int[] nums) {
        int max = Integer.MIN_VALUE, maxEndingHere = Integer.MIN_VALUE;
        for (int i = 0, len = nums.length; i < len; ++i) {
            final int val = nums[i];
            if (maxEndingHere > 0) {
                maxEndingHere += val;
            } else {
                maxEndingHere = val;
            }
            max = Math.max(max, maxEndingHere);
        }
        return max;
    }

    // 80ms beats 2.21%
    public static int maxSubArrayDC(int[] nums) {
        return maxSubArrayDC(nums, 0, nums.length - 1).max();
    }

    private static Result maxSubArrayDC(int[] nums, int from, int to) {
        if (from == to) {
            final int val = nums[from];
            return new Result(val, val, val, val);
        }

        final int mid = (from + to) / 2;

        final Result left = maxSubArrayDC(nums, from, mid);
        final Result right = maxSubArrayDC(nums, mid + 1, to);

        final int maxSumFromLeft = Math.max(left.maxSumFromLeft, left.sum + right.maxSumFromLeft);
        final int maxSumFromRight = Math.max(right.maxSumFromRight, right.sum + left.maxSumFromRight);
        final int max = IntStream.of(maxSumFromLeft, maxSumFromRight, left.maxSumFromRight + right.maxSumFromLeft, left.max, right.max).max().getAsInt();

        return new Result(maxSumFromLeft, maxSumFromRight, max, left.sum + right.sum);
    }

    private static record Result(int maxSumFromLeft, int maxSumFromRight, int max, int sum) {};
}
// @lc code=end
