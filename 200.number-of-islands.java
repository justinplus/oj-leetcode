/*
 * @lc app=leetcode id=200 lang=java
 *
 * [200] Number of Islands
 */

// @lc code=start
// TODO: do width-frist traversal
class Solution {
    public int numIslands(char[][] grid) {
        final boolean[][] flag = new boolean[grid.length][grid[0].length];
        final int width = flag.length, len = flag[0].length;

        int cnt = 0;
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < len; ++j) {
                if (grid[i][j] == '1' && !flag[i][j]) {
                    ++cnt;
                    visit(i, j, width, len, grid, flag);
                }
            }
        }
        return cnt;
    }

    private static void visit(int i, int j, int width, int len, char[][] grid, boolean[][] flag) {
        if (i < 0 || i >= width || j < 0 || j >= len || flag[i][j]) {
            return;
        }
        flag[i][j] = true;
        if (grid[i][j] == '1') {
            visit(i - 1, j, width, len, grid, flag);
            visit(i + 1, j, width, len, grid, flag);
            visit(i, j - 1, width, len, grid, flag);
            visit(i, j + 1, width, len, grid, flag);
        }
    }
}
// @lc code=end

