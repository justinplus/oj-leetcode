/*
 * @lc app=leetcode id=97 lang=java
 *
 * [97] Interleaving String
 */

// @lc code=start
// TODO: enhance memory to 0(n) and fail fast
class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        final int m = s1.length(), n = s2.length();
        if (m + n != s3.length()) {
            return false;
        }

        final char[] charArr1 = s1.toCharArray();
        final char[] charArr2 = s2.toCharArray();
        final char[] charArr3 = s3.toCharArray();

        final boolean[][] matrix = new boolean[m + 1][n + 1];
        matrix[0][0] = true;
        for (int i = 0; i < m && charArr1[i] == charArr3[i]; matrix[++i][0] = true);
        for (int j = 0; j < n && charArr2[j] == charArr3[j]; matrix[0][++j] = true);

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                final char next = charArr3[i + j - 1];
                matrix[i][j] = matrix[i - 1][j] && charArr1[i - 1] == next
                || matrix[i][j - 1] && charArr2[j - 1] == next;
            }
        }

        return matrix[m][n];
    }
}
// @lc code=end

