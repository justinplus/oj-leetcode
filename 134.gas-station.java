/*
 * @lc app=leetcode id=134 lang=java
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        final int len = gas.length;

        for (int i = 0; i < len;) {
            int remained = 0;
            int j = i;
            do {
                remained += gas[j] - cost[j];
                j = j + 1 >= len ? j + 1 - len : j + 1;
            } while (j != i && remained >= 0);

            if (j == i) {
                return remained >=0 ? i : -1;
            } else if (i > j) {
                return -1;
            } else {
                i = j;
            }
        }

        return -1;
    }
}
// @lc code=end
