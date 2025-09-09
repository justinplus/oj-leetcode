/*
 * @lc app=leetcode id=1 lang=java
 *
 * [1] Two Sum
 */

import java.util.HashMap;
import java.util.Map;

// @lc code=start
class Solution {
    public int[] twoSum(int[] nums, int target) {
        final Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0, len = nums.length; i < len; ++i) {
            final int num = nums[i];
            final Integer index = map.get(target - num);
            if (index == null) {
                map.put(num, i);
            } else {
                return new int[] {index, i};
            }
        }

        return new int[] {-1, -1};
    }
}
// @lc code=end

