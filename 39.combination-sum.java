/*
 * @lc app=leetcode id=39 lang=java
 *
 * [39] Combination Sum
 */

import java.util.ArrayList;
import java.util.List;

// @lc code=start
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        final int[] counter = new int[candidates.length];
        final List<List<Integer>> result = new ArrayList<>();
        combine(candidates, counter, 0, 0, target, result);
        return result;
    }

    private static void combine(int[] candidates, int[] counter, int sum, int index, int target,
            List<List<Integer>> result) {
        for (; sum <= target; counter[index]++, sum += candidates[index]) {
            if (sum == target) {
                result.add(buildResult(counter, candidates));
            } else if (index + 1 < counter.length) {
                combine(candidates, counter, sum, index + 1, target, result);
            }
        }
        counter[index] = 0;
    }

    private static List<Integer> buildResult(int[] counter, int[] candidates) {
        final List<Integer> result = new ArrayList<>();
        for (int i = 0, len = counter.length; i < len; ++i) {
            for (int j = 0; j < counter[i]; ++j) {
                result.add(candidates[i]);
            }
        }
        return result;
    }
}
// @lc code=end
