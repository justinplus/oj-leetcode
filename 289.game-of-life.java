/*
 * @lc app=leetcode id=289 lang=java
 *
 * [289] Game of Life
 */

// @lc code=start
class Solution {
    private static final int[][] NEXT_GEN = {
        {0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 0} 
    };

    public void gameOfLife(int[][] board) {
        final int m = board.length;
        final int n = board[0].length;

        for (int j = 0; j < n; ++j) {
            updateToNextGen(board, m, n, 0, j);
        }

        if (m > 1) {
            for (int j = 0; j < n; ++j) {
                updateToNextGen(board, m, n, m - 1, j);
            }
        }

        for (int i = 1; i < m - 1; ++i) {
            updateToNextGen(board, m, n, i, 0);
        }

        if (n > 1) {
            for (int i = 1; i < m - 1; ++i) {
                updateToNextGen(board, m, n, i, n - 1);
            }
        }

        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) { 
                updateToNextGen(board, i, j);
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] /= 2;
            }
        }
    }

    private static void updateToNextGen(int[][] board, int m, int n, int i, int j) {
        final int current = board[i][j];
        final int aliveNeighborCount = getAliveNeighborCount(board, m, n, i, j);
        board[i][j] += NEXT_GEN[current][aliveNeighborCount] * 2;
    }

    private static void updateToNextGen(int[][] board, int i, int j) {
        final int current = board[i][j];
        final int aliveNeighborCount = getAliveNeighborCount(board, i, j);
        board[i][j] += NEXT_GEN[current][aliveNeighborCount] * 2;
    }

    private static int getAliveNeighborCount(int[][] board, int i, int j) {
        return board[i - 1][j - 1] % 2 + board[i - 1][j] % 2 + board[i - 1][j + 1] % 2
                + board[i][j - 1] % 2 + board[i][j + 1] % 2
                + board[i + 1][j - 1] % 2 + board[i + 1][j] % 2 + board[i + 1][j + 1] % 2;
    }

    private static int getAliveNeighborCount(int[][] board, int m, int n, int i, int j) {
        int count = 0;
        if (i - 1 >= 0) {
            if (j - 1 >= 0) {
                count += board[i - 1][j - 1] % 2;
            }
            count += board[i - 1][j] % 2;
            if (j + 1 < n) {
                count += board[i - 1][j + 1] % 2;
            }
        }

        if (j - 1 >= 0) {
            count += board[i][j - 1] % 2;
        }
        if (j + 1 < n) {
            count += board[i][j + 1] % 2;
        }

        if (i + 1 < m) {
            if (j - 1 >= 0) {
                count += board[i + 1][j - 1] % 2;
            }
            count += board[i + 1][j] % 2;
            if (j + 1 < n) {
                count += board[i + 1][j + 1] % 2;
            }
        }
        return count;
    }
}
// @lc code=end
