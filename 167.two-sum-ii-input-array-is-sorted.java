/*
 * @lc app=leetcode id=167 lang=java
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

import java.util.Arrays;
// @lc code=start
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        for (int i = 0; i < numbers.length - 1; ++i) {
            // final int curr = numbers[i];
            // NOTE: Pruning not help (2ms -> 3ms) 
            // if (target < curr + numbers[i+1] || target > curr + numbers[numbers.length - 1]) {
            //    continue;
            //}

            final int remainder = target - numbers[i];
            final int index = Arrays.binarySearch(numbers, i + 1, numbers.length, remainder);
            if (index > 0) {
                return new int[] {i + 1, index + 1};
            }
        }
        return null;
    }
}
// @lc code=end
