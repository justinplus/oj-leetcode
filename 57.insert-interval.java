/*
 * @lc app=leetcode id=57 lang=java
 *
 * [57] Insert Interval
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

// @lc code=start
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        final int pos = Arrays.binarySearch(intervals, newInterval,
                (int[] a, int[] b) -> Integer.compare(a[0], b[0]));
        // NOTE: error case [[1,5]], [1,7]
        // final int priorIndex = pos > 0 ? pos : -pos - 2;
        final int priorIndex = pos >= 0 ? pos : -pos - 2;

        final List<int[]> list = new ArrayList<>();
        for (int i = 0 ; i <= priorIndex; ++i) {
            list.add(intervals[i]);
        }

        if (pos == -1) {
            list.add(newInterval);
        } else if (pos > 0) {
            intervals[priorIndex][1] = Math.max(intervals[priorIndex][1], newInterval[1]);
        } else {
            final int[] itv = intervals[priorIndex];
            if (itv[1] >= newInterval[0]) {
                itv[1] = Math.max(itv[1], newInterval[1]);
            } else {
                list.add(newInterval);
            }
        }

        for (int i = priorIndex + 1, len = intervals.length; i < len; ++i) {
            final int[] curr = list.getLast();
            final int[] next = intervals[i];
            if (curr[1] >= next[0]) {
                curr[1] = Math.max(curr[1], next[1]);
            } else {
                for (int j = i; j < len; ++j) {
                    list.add(intervals[j]);
                }
                break;
            }
        }

        return list.toArray(new int[0][]);
    }
}
// @lc code=end

