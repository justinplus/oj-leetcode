/*
 * @lc app=leetcode id=79 lang=java
 *
 * [79] Word Search
 */

// @lc code=start
// TODO: 107ms beats 95.33%
//   Follow up: Could you use search pruning to make your solution faster with a larger board?
class Solution {
    public boolean exist(char[][] board, String word) {
        final int m = board.length, n = board[0].length;
        final boolean[][] visited = new boolean[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (exist(board, visited, i, j, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }

    public boolean exist(char[][] board, boolean[][] visited, int i, int j, int index, String word) {
        final int m = board.length, n = board[0].length;
        visited[i][j] = true;
        if (board[i][j] == word.charAt(index)) {
            if (index == word.length() - 1) {
                return true;
            }
            if (i - 1 >= 0 && !visited[i - 1][j] && exist(board, visited, i - 1, j, index + 1, word)
                    || i + 1 < m && !visited[i + 1][j] && exist(board, visited, i + 1, j, index + 1, word)
                    || j - 1 >= 0 && !visited[i][j - 1] && exist(board, visited, i, j - 1, index + 1, word)
                    || j + 1 < n && !visited[i][j + 1] && exist(board, visited, i, j + 1, index + 1, word)) {
                return true;
            }
        }
        visited[i][j] = false;
        return false;
    }
}
// @lc code=end
