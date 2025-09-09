/*
 * @lc app=leetcode id=45 lang=java
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
    public int jump(int[] nums) {
        final int len = nums.length;
        // NOTE: cornor case [0], [1]
        if (len == 1) {
            return 0;
        }
        int minSteps = 0;
        for (int i = 0, farthestIndex = 0; i < len;) {
            int nextFarthestIndex = farthestIndex;
            ++minSteps;
            while (i <= farthestIndex) {
                nextFarthestIndex = Math.max(nextFarthestIndex, i + nums[i]);
                if (nextFarthestIndex >= len - 1) {
                    return minSteps;
                }
                ++i;
            }
            farthestIndex = nextFarthestIndex;
        }

        return minSteps;
    }
}
// @lc code=end

