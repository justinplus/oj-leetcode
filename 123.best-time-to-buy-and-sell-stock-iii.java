/*
 * @lc app=leetcode id=123 lang=java
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
    public int maxProfit(int[] prices) {
        return maxProfit4State(prices);
    }

    private static int maxProfit1D(int[] prices) {
        final int len = prices.length;
        final int[] maxProfit1 = new int[len];
        // maxProfit1[0] = 0;
        final int[] maxProfit2 = new int[len + 1];
        // maxProfit2[len - 1] = maxProfit2[len] = 0;

        for (int i = 1, min = prices[0]; i < len; ++i) {
            final int p = prices[i];
            if (p > min) {
                maxProfit1[i] = Math.max(maxProfit1[i - 1], p - min);
            } else {
                min = p;
            }
        }

        for (int i = len - 2, max = prices[len - 1]; i >= 0; --i) {
            final int p = prices[i];
            if (p < max) {
                maxProfit2[i] = Math.max(maxProfit2[i + 1], max - p);
            } else {
                max = p;
            }
        }

        int maxProfit = 0;
        for (int i = 0; i < len; ++i ) {
            maxProfit = Math.max(maxProfit, maxProfit1[i] + maxProfit2[i + 1]);
        }

        return maxProfit;
    }

    // TODO: review the state formula
    private static int maxProfit4State(int[] prices) {
        int b1 = -prices[0], s1 = 0, b2 = -prices[0], s2 = 0;

        for (int i = 1, len = prices.length; i < len; ++i) {
            final int p = prices[i];
            s2 = Math.max(s2, b2 + p);
            b2 = Math.max(b2, s1 - p);
            s1 = Math.max(s1, b1 + p);
            b1 = Math.max(b1, -p);
        }

        return Math.max(s1, s2);
    }

    // NOTE: time limit exceeded
    private static int maxProfit2D(int[] prices) {
        final int len = prices.length;
        int maxProfit = 0;
        for (int min1 = prices[0], maxProfit1 = 0, i = 1; i < len; ++i) {
            if (prices[i] > min1) {
                maxProfit1 = prices[i] - min1;
            } else {
                min1 = prices[i];
            }
            int maxProfit2 = 0;
            for (int j = i + 1, min2 = Integer.MAX_VALUE; j < len - 1; ++j) {
                if (prices[j] > min2) {
                    maxProfit2 = prices[j] - min2;
                } else {
                    min2 = prices[j];
                }
            }
            maxProfit = maxProfit1 + maxProfit2;
        }
        return maxProfit;
    }
}
// @lc code=end

