/*
 * @lc app=leetcode id=122 lang=java
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
    public int maxProfit(int[] prices) {
        final int len = prices.length;
        if (len <= 1) {
            return 0;
        }
        int sum = 0, buyPrice = prices[0];
        for (int i = 1; i < len; ++i) {
            if (prices[i] < prices[i - 1]) {
                final int profit = prices[i - 1] - buyPrice;
                if (profit > 0) {
                    sum += profit;
                }
                buyPrice = prices[i];
            }
        }

        final int profit = prices[len - 1] - buyPrice;
        if (profit > 0) {
            sum += profit;
        }
        return sum;
    }
}
// @lc code=end
