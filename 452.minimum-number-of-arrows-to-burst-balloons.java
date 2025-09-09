/*
 * @lc app=leetcode id=452 lang=java
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

import java.util.Arrays;
// @lc code=start
class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, (int[] a, int[] b) -> Integer.compare(a[0], b[0]));
        int count = 0;
        for (int i = 0, j = 1, len = points.length; j < len; ++j) {
            int[] curr = points[i];
            int[] next = points[j];

            if (curr[1] >= next[0]) {
                curr[0] = Math.max(curr[0], next[0]);
                curr[1] = Math.min(curr[1], next[1]);
            } else {
                ++count;
                i = j;
            }
        }

        return count + 1;
    }
}
// @lc code=end

