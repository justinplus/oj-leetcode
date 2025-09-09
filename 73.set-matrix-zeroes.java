/*
 * @lc app=leetcode id=73 lang=java
 *
 * [73] Set Matrix Zeroes
 */

import java.util.Arrays;
import java.util.stream.IntStream;
// @lc code=start
class Solution {
    public void setZeroes(int[][] matrix) {
        final int m = matrix.length;
        final int n = matrix[0].length;

        final boolean isFirstRowZero = IntStream.of(matrix[0]).anyMatch(i -> i == 0);
        boolean isFirstColZero = false;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                isFirstColZero = true;
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 1; j < n; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (isFirstRowZero) {
            Arrays.fill(matrix[0], 0);
        }

        if (isFirstColZero) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }

    public void setZeroesExtraSpace(int[][] matrix) {
        final int m = matrix.length;
        final int n = matrix[0].length;

        final boolean[] vertical = new boolean[m];
        final boolean[] horizontal = new boolean[n];

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    vertical[i] = true;
                    horizontal[j] = true;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            if (vertical[i]) {
                Arrays.fill(matrix[i], 0);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (horizontal[i]) {
                for (int j = 0; j < m; ++j) {
                    matrix[j][i] = 0;
                }
            }
        }
    }
}
// @lc code=end

