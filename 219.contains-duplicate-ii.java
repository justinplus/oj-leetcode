/*
 * @lc app=leetcode id=219 lang=java
 *
 * [219] Contains Duplicate II
 */

import java.util.HashMap;
import java.util.Map;

// @lc code=start
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        final Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0, len = nums.length; i < len; ++i) {
            final int num = nums[i];
            final Integer furthestIndex = map.get(num);
            
            if (furthestIndex != null && i - furthestIndex <= k) {
                return true;
            } else {
                map.put(num, i);
            }
        }

        return false;
    }
}
// @lc code=end

