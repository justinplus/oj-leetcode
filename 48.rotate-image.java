/*
 * @lc app=leetcode id=48 lang=java
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
    public void rotate(int[][] matrix) {
        for (int i = 0, len = matrix.length, max = len / 2; i < max; ++i) {
            for (int j = i; j < len - i - 1; ++j) {
                swap(matrix, i, j, j, len - i - 1);
                swap(matrix, i, j, len - i - 1, len - j - 1);
                swap(matrix, i, j, len - j - 1, i);
            }
        }
    }

    private static void swap(int[][] matrix, int i1, int j1, int i2, int j2) {
        final int tmp = matrix[i1][j1];
        matrix[i1][j1] = matrix[i2][j2];
        matrix[i2][j2] = tmp;
    }
}
// @lc code=end

