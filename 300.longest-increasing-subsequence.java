/*
 * @lc app=leetcode id=300 lang=java
 *
 * [300] Longest Increasing Subsequence
 */

import java.util.Arrays;

// @lc code=start
class Solution {
    // nlogn
    public int lengthOfLIS(int[] nums) {
        final int len = nums.length;
        final int[] ends = new int[len];
        ends[0] = nums[0];
        int lenOfLIS = 1;

        for (int i = 1; i < len; ++i) {
            final int target = nums[i];
            final int index = Arrays.binarySearch(ends, 0, lenOfLIS, target);
            if (index < 0) {
                final int insertIndex = -index - 1;
                ends[insertIndex] = target;
                lenOfLIS = Math.max(lenOfLIS, insertIndex + 1);
            }
        }
        return lenOfLIS;
    }

    // n^2
    public int lengthOfLIS1(int[] nums) {
        final int len = nums.length;
        final int[] length = new int[len];

        int lengthOfLIS = 1;
        for (int i = 0; i < len; ++i) {
            int max = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    max = Math.max(max, length[j]);
                }
            }
            length[i] = max + 1;
            lengthOfLIS = Math.max(lengthOfLIS, max + 1);

        }
        return lengthOfLIS;
    }
}
// @lc code=end
