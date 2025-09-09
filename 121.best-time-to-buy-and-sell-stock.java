/*
 * @lc app=leetcode id=121 lang=java
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
    public int maxProfit(int[] prices) {
        final int len = prices.length;
        if (len <= 1) {
            return 0;
        }

        int maxProfix = 0;
        for (int i = 1, min = prices[0]; i < len; ++i) {
            final int profit = prices[i] - min;
            if (profit > maxProfix) {
                maxProfix = profit;
            }
            
            if (prices[i] < min) {
                min = prices[i];
            }
        }

        return maxProfix;
    }
}
// @lc code=end

