/*
 * @lc app=leetcode id=77 lang=java
 *
 * [77] Combinations
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

// @lc code=start
// TODO: review
class Solution {
    public List<List<Integer>> combine(int n, int k) {
        final Integer[] arr = new Integer[k];
        final List<List<Integer>> result = new ArrayList<>();
        fillCombinations(n, k, 0, 0, arr, result);
        return result;
    }

    private static void fillCombinations(int n, int k, int index, int offset, Integer[] arr, List<List<Integer>> result) {
        if (index == k) {
            result.add(Arrays.asList(arr.clone()));
        } else {
            // Tip
            for (int i = offset; i < n - k + 1 + index; ++i) {
                arr[index] = i + 1;
                fillCombinations(n, k, index + 1, i + 1, arr, result);
            }
        }
    }
}
// @lc code=end
