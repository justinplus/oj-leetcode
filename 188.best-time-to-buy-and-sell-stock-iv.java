/*
 * @lc app=leetcode id=188 lang=java
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

import java.util.Arrays;
import java.util.stream.IntStream;

// @lc code=start
// TODO: get the backstrace
class Solution {
    public int maxProfit(int k, int[] prices) {
        final int[] buy = new int[k];
        Arrays.fill(buy, -prices[0]);
        final int[] sell = new int[k];

        for (int i = 1, len = prices.length; i < len; ++i) {
            final int p = prices[i];
            for (int j = k - 1; j > 0; --j) {
                sell[j] = Math.max(sell[j], buy[j] + p);
                buy[j] = Math.max(buy[j], sell[j - 1] - p);
            }

            sell[0] = Math.max(sell[0], buy[0] + p);
            buy[0] = Math.max(buy[0], -p);
        }

        return IntStream.of(sell).max().getAsInt();
    }
}
// @lc code=end

