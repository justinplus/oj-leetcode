/*
 * @lc app=leetcode id=54 lang=java
 *
 * [54] Spiral Matrix
 */

import java.util.ArrayList;
import java.util.List;
// @lc code=start
class Solution {
    // TODO: try using top, left, right, bottom
    public List<Integer> spiralOrder(int[][] matrix) {
        final int m = matrix.length;
        final int n = matrix[0].length;

        final List<Integer> result = new ArrayList<>();
        final int minDim = Math.min(m, n);
        for (int i = 0, len = minDim / 2 == 0 ? minDim / 2 : minDim / 2 + 1; i < len; ++i) {
            for (int j = i; j < n - i; ++j) {
                result.add(matrix[i][j]);
            }

            for (int j = i + 1; j < m - i - 1; ++j) {
                result.add(matrix[j][n - i - 1]);
            }

            if (m - i - 1 > i) {
                for (int j = n - i - 1; j >= i; --j) {
                    result.add(matrix[m - i - 1][j]);
                }
            }

            if (i < n - i - 1) {
                for (int j = m - i - 2; j >= i + 1; --j) {
                    result.add(matrix[j][i]);
                }
            }
        }

        return result;
    }
}
// @lc code=end

