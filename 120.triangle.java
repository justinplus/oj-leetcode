/*
 * @lc app=leetcode id=120 lang=java
 *
 * [120] Triangle
 */

import java.util.List;
import java.util.stream.IntStream;

// @lc code=start
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        return minimumTotalBottomUp(triangle);
    }

    public int minimumTotalBottomUp(List<List<Integer>> triangle) {
        final int len = triangle.size();
        // Tip: the cost of stream is high, which takes 2ms for 46 test cases
        // final int[] s = triangle.get(len - 1).stream().mapToInt(Integer::intValue).toArray();
        final int[] s = new int[len + 1];

        for (int i = len - 1; i >= 0; --i) {
            final List<Integer> row = triangle.get(i);
            for (int j = 0; j <= i; ++j) {
                s[j] = Math.min(s[j], s[j + 1]) + row.get(j);
            }
        }

        return s[0];
    }

    public int minimumTotalTopDown(List<List<Integer>> triangle) {
        final int len = triangle.size();
        int[] s1 = new int[len], s2 = new int[len];
        s1[0] = triangle.get(0).get(0);

        for (int i = 1; i < len; ++i) {
            final List<Integer> row = triangle.get(i);
            s2[0] = s1[0] + row.get(0);
            s2[i] = s1[i - 1] + row.get(i);
            for (int j = 1; j < i; ++j) {
                s2[j] = Math.min(s1[j - 1], s1[j]) + row.get(j);
            }

            final int[] s = s1;
            s1 = s2;
            s2 = s;
        }

        return IntStream.of(s1).min().getAsInt();
    }
}
// @lc code=end

