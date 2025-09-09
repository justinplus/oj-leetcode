/*
 * @lc app=leetcode id=56 lang=java
 *
 * [56] Merge Intervals
 */

import java.util.Arrays;
// @lc code=start
class Solution {
    // NOTE: corner case: [[1,4],[2,3]] -> [[1, 4]] not [[1, 3]]
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (int[] a, int[] b) -> Integer.compare(a[0], b[0]));
        final int len = intervals.length;
        int mergeCnt = 0;
        for (int i = 0, j = 1; j < len; ++j) {
            if (intervals[i][1] >= intervals[j][0]) {
                if (intervals[j][1] > intervals[i][1]) {
                    intervals[i][1] = intervals[j][1];
                }
                intervals[j] = null;
                ++mergeCnt;
            } else {
                i = j;
            }
        }
        final int[][] result = new int[intervals.length - mergeCnt][];
        for (int i = 0, j = 0; i < len; ++i) {
            if (intervals[i] != null) {
                result[j++] = intervals[i];
            }
        }
        return result;
    }
}
// @lc code=end
