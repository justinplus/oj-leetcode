/*
 * @lc app=leetcode id=72 lang=java
 *
 * [72] Edit Distance
 */

// @lc code=start
// TODO: review & understand the approval
// TODO: practice a similar problem
class Solution {
    public int minDistance(String word1, String word2) {
        final char[] charArr1 = word1.toCharArray();
        final char[] charArr2 = word2.toCharArray();
        final int m = word1.length(), n = word2.length();
        // TODO: reduce the memory usage
        final int[][] matrix = new int[m + 1][n + 1];

        // init matrix
        matrix[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            matrix[i][0] = i;
        }
        for (int j = 1; j <= n; ++j) {
            matrix[0][j] = j;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                final int cross = matrix[i - 1][j - 1]
                        + (charArr1[i - 1] == charArr2[j - 1] ? 0 : 1);
                matrix[i][j] = Math.min(cross,
                        Math.min(matrix[i - 1][j], matrix[i][j - 1]) + 1);
            }
        }

        return matrix[m][n];
    }
}
// @lc code=end

