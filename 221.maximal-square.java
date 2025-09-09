/*
 * @lc app=leetcode id=221 lang=java
 *
 * [221] Maximal Square
 */

// @lc code=start
// TODO: review and review space to O(n)
class Solution {
    private static final char CHAR_ONE = '1';
    private static final char CHAR_ZERO = '0';

    public int maximalSquare(char[][] matrix) {
        final int m = matrix.length, n = matrix[0].length;

        final int[][] squares = new int[m][n];
        int max = 0;
        for (int i = 0; i < m; ++i) {
            squares[i][0] = matrix[i][0] - CHAR_ZERO;
            max = Math.max(max, squares[i][0]);
        }

        for (int j = 1; j < n; ++j) {
            squares[0][j] = matrix[0][j] - CHAR_ZERO;
            max = Math.max(max, squares[0][j]);
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == CHAR_ONE) {
                    squares[i][j] = 1 + Math.min(squares[i - 1][j - 1], Math.min(squares[i - 1][j], squares[i][j - 1]));
                    max = Math.max(max, squares[i][j]);
                } 
            }
        }

        return max * max;
    }
}
// @lc code=end
