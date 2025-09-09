/*
 * @lc app=leetcode id=74 lang=java
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int left = 0, right = m * n - 1;
        while (left <= right) {
            final int med = (left + right) / 2;
            final int val = matrix[med / n][med % n];
            if (val == target) {
                return true;
            } else if (val < target) {
                left = med + 1;
            } else {
                right = med - 1;
            }
        }

        return false;
    }
}
// @lc code=end
