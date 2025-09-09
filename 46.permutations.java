/*
 * @lc app=leetcode id=46 lang=java
 *
 * [46] Permutations
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

// @lc code=start
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        final boolean[] inUse = new boolean[nums.length];
        final Integer[] arr = new Integer[nums.length];
        final List<List<Integer>> result = new ArrayList<>();
        fillPermutations(nums, inUse, arr, 0, result);
        return result;
    }

    private static void fillPermutations(int[] nums, boolean[] inUse, Integer[] arr, int index,
            List<List<Integer>> result) {
        if (index == nums.length) {
            result.add(Arrays.asList(arr.clone()));
        } else {
            for (int i = 0; i < nums.length; ++i) {
                if (!inUse[i]) {
                    inUse[i] = true;
                    arr[index] = nums[i];
                    fillPermutations(nums, inUse, arr, index + 1, result);
                    inUse[i] = false;
                }
            }
        }
    }
}
// @lc code=end
