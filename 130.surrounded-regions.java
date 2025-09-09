/*
 * @lc app=leetcode id=130 lang=java
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
    private static final char CHAR_O = 'O';
    private static final char CHAR_C = 'C';
    private static final char CHAR_X = 'X';
    
    public void solve(char[][] board) {
        final int m = board.length, n = board[0].length;
        if (m <= 2 || n <= 2) {
            return;
        }

        for (int i = 0; i < m; ++i) {
            if (board[i][0] == CHAR_O) {
               connect(board, i, 0, m, n);
            }
            if (board[i][n - 1] == CHAR_O) {
               connect(board, i, n - 1, m, n);
            }
        }

        for (int j = 0; j < n; ++j) {
            if (board[0][j] == CHAR_O) {
                connect(board, 0, j, m, n);
            }
            if (board[m - 1][j] == CHAR_O) {
                connect(board, m - 1, j, m, n);
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == CHAR_O) {
                    board[i][j] = CHAR_X;
                }
                if (board[i][j] == CHAR_C) {
                    board[i][j] = CHAR_O;
                }
            }
        }
    }

    private static void connect(char[][] board, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == CHAR_C) {
            return;
        }

        if (board[i][j] == CHAR_O) {
            board[i][j] = CHAR_C;
            connect(board, i - 1, j, m, n);
            connect(board, i + 1, j, m, n);
            connect(board, i, j - 1, m, n);
            connect(board, i, j + 1, m, n);
        }
    }
}
// @lc code=end

