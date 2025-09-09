/*
 * @lc app=leetcode id=209 lang=java
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
// TODO: find a solution which is O(nlogn)
class Solution {
    // use slidind window - O(n)
    public int minSubArrayLen(int target, int[] nums) {
        assert nums.length > 0 && target > 0;

        int minLen = Integer.MAX_VALUE;
        for (int left = -1, right = 0, sum = 0, len = nums.length; right < len; ++right) {
            sum += nums[right];

            while (sum >= target) {
                minLen = Math.min(minLen, right - left);
                if (minLen == 1) {
                    return 1;
                }
                sum -= nums[++left];
            }
        }
        return minLen == Integer.MAX_VALUE ? 0 : minLen;
    }

    // use slidind window - O(n)
    public int minSubArrayLenSlidingWindow(int target, int[] nums) {
        assert nums.length > 0 && target > 0;

        int minLen = Integer.MAX_VALUE;
        for (int left = -1, right = 0, sum = nums[0];;) {
            if (sum >= target) {
                minLen = Math.min(minLen, right - left);
                if (minLen == 1) {
                    return 1;
                }
                sum -= nums[++left];
            } else {
                if (right >= nums.length - 1) {
                    break;
                }
                sum += nums[++right];
            }
        }
        return minLen == Integer.MAX_VALUE ? 0 : minLen;
    }

    // Time Limit Exceeded - O(n^2)
    public int minSubArrayLenPrefixSum(int target, int[] nums) {
        assert nums.length > 0;

        final int[] sums = new int[nums.length];
        sums[0] = nums[0];
        if (nums[0] >= target) {
            return 1;
        }

        int minLen = nums.length;
        for (int i = 1; i < sums.length; ++i) {
            sums[i] = sums[i-1] + nums[i];
            if (sums[i] >= target) {
                minLen = Math.min(minLen, i + 1);
            }
        }

        if (sums[sums.length - 1] < target) {
            return 0;
        }

        for (int i = 0, len = nums.length; i < len - 1; ++i) {
            for (int j = i + 1; j < len; ++j) {
                if (sums[j] - sums[i] >= target) {
                    minLen = Math.min(minLen, j - i);
                    if (minLen == 1) {
                        return 1;
                    }
                }
            }
        }

        return minLen;
    }
}
// @lc code=end

