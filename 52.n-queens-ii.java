/*
 * @lc app=leetcode id=52 lang=java
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution {
    public int totalNQueens(int n) {
        final boolean[][] flags = new boolean[][] {
            new boolean[n],
            new boolean[n],
            new boolean[2 * n - 1],
            new boolean[2 * n - 1],
        };

        return place(flags, 0, n);
    }

    private static int place(boolean[][] flags, int level, int n) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (canSet(flags, level, j, n)) {
                if (level == n - 1) {
                    cnt += 1;
                } else {
                    set(flags, level, j, n);
                    cnt += place(flags, level + 1, n);
                    clear(flags, level, j, n);
                }
            }
        }
        return cnt;
    }

    private static boolean canSet(boolean[][] flags, int i, int j, int n) {
        return !flags[0][i] && !flags[1][j] &&
                !flags[2][i + j] && !flags[3][i + n - 1 - j];
    }

    private static void set(boolean[][] flags, int i, int j, int n) {
        flags[0][i] = true;
        flags[1][j] = true;
        flags[2][i + j] = true;
        flags[3][i + n - 1 - j] = true;
    }

    private static void clear(boolean[][] flags, int i, int j, int n) {
        flags[0][i] = false;
        flags[1][j] = false;
        flags[2][i + j] = false;
        flags[3][i + n - 1 - j] = false;
    }
}
// @lc code=end
