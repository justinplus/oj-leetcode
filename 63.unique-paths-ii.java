/*
 * @lc app=leetcode id=63 lang=java
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        final int m = obstacleGrid.length, n = obstacleGrid[0].length;
        int[] s1 = new int[n], s2 = new int[n];
        for (int j = 0; j < n; ++j) {
            if (obstacleGrid[0][j] == 0) {
                s1[j] = 1;
            } else {
                break;
            }
        }

        for (int i = 1; i < m; ++i) {
            final int[] row = obstacleGrid[i];
            s2[0] = row[0] == 1 ? 0 : s1[0];
            for (int j = 1; j < n; ++j) {
                s2[j] = row[j] == 1 ? 0 : s2[j - 1] + s1[j];
            }

            final int[] s = s1;
            s1 = s2;
            s2 = s;
        }

        return s1[n - 1];
    }
}
// @lc code=end

