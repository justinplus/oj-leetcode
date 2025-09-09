/*
 * @lc app=leetcode id=909 lang=java
 *
 * [909] Snakes and Ladders
 */

import java.util.ArrayDeque;
import java.util.Deque;

// @lc code=start
class Solution {
    public int snakesAndLadders(int[][] board) {
        final int n = board.length;
        final int len = n * n;
        final boolean[] visited = new boolean[len];
        final int[] arr = flatten(board);

        Deque<Integer> q1 = new ArrayDeque<>(128);
        Deque<Integer> q2 = new ArrayDeque<>(128);
        q1.add(0);
        visited[0] = true;

        int cnt = 0;
        while (!q1.isEmpty()) {
            ++cnt;
            do {
                final int cell = q1.removeFirst();
                final int limit = Math.min(len - 1, cell + 6);
                int j = cell + 1;
                for (; j <= limit; ++j) {
                    final int next = arr[j] == -1 ? j : arr[j] - 1;
                    if (!visited[next]) {
                        if (next == len - 1) {
                            return cnt;
                        }
                        q2.addLast(next);
                        visited[next] = true;
                    }
                }
            } while (!q1.isEmpty());

            final Deque<Integer> q = q1;
            q1 = q2;
            q2 = q;
        }

        return -1;
    }

    private static int[] flatten(int[][] board) {
        final int n = board.length;
        final int[] arr = new int[n * n];
        for (int i = n - 1, k = 0; i >= 0; --i) {
            final int row = n - i - 1;
            if (row % 2 == 0) {
                for (int j = 0; j < n; ++j) {
                    arr[k++] = board[i][j];
                }
            } else {
                for (int j = n - 1; j >= 0; --j) {
                    arr[k++] = board[i][j];
                }
            }
        }
        return arr;
    }
}
// @lc code=end
