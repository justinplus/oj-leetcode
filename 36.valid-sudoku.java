/*
 * @lc app=leetcode id=36 lang=java
 *
 * [36] Valid Sudoku
 */

import java.util.HashSet;
import java.util.Set;
// @lc code=start
class Solution {
    public boolean isValidSudoku(char[][] board) {
        final int len = 9;
        final int subLen = 3;
        final char dot = '.';
        final Set<Character> set = new HashSet<>();

        for (int i = 0; i < len; ++i) {
            set.clear();
            for (int j = 0; j < len; ++j) {
                final char c = board[i][j];
                if (c != dot) {
                    if(!set.add(c)) {
                        return false;
                    }
                }
            }
            set.clear();
            for (int j = 0; j < len; ++j) {
                final char c = board[j][i];
                if (c != dot) {
                    if (!set.add(c)) {
                        return false;
                    }
                }
            }
        }

        for (int i = 0; i < len; i += subLen) {
            for (int j = 0; j < len; j += subLen) {
                set.clear();
                for (int ii = 0; ii < subLen; ++ii) {
                    for (int jj = 0; jj < subLen; ++jj) {
                        final char c = board[i+ii][j+jj];
                        if (c != dot) {
                            if (!set.add(c)) {
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
}
// @lc code=end

