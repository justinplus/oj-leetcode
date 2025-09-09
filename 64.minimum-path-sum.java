/*
 * @lc app=leetcode id=64 lang=java
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
// TODO: 3ms beats 69.84% - improve performance
class Solution {
    public int minPathSum(int[][] grid) {
        final int m = grid.length, n = grid[0].length;
        int[] s1 = new int[n], s2  = new int[n];
        s1[0] = grid[0][0];
        for (int j = 1; j < n; ++j) {
            s1[j] = s1[j - 1] + grid[0][j];
        }

        for (int i = 1; i < m; ++i) {
            final int[] row = grid[i];
            s2[0] = s1[0] + row[0];
            for (int j = 1; j < n; ++j) {
                s2[j] = Math.min(s2[j - 1], s1[j]) + row[j];
            }

            final int[] s = s1;
            s1 = s2;
            s2 = s;
        }

        return s1[n - 1];
    }
}
// @lc code=end
