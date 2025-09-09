/*
 * @lc app=leetcode id=11 lang=java
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
    public int maxArea(int[] height) {
        int maxAera = 0;

        for (int i = 0, j = height.length - 1; i < j; ) {
            final int h1 = height[i];
            final int h2 = height[j];
            maxAera = Math.max(maxAera, Math.min(h1, h2) * (j - i));
            if (h1 == h2) {
                // NOTE: important greedy logic
                while(++i < j && h1 >= height[i]);
                while(i < --j && h2 >= height[j]);
            } else if (h1 > h2) {
                while(i < --j && h2 >= height[j]);
            } else {
                while(++i < j && h1 >= height[i]);
            }
        }

        return maxAera;
    }
}
// @lc code=end

