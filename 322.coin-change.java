/*
 * @lc app=leetcode id=322 lang=java
 *
 * [322] Coin Change
 */

// @lc code=start
// TODO: 22ms beats 35.42% - improve performance
class Solution {
    public int coinChange(int[] coins, int amount) {
        if (amount == 0) {
            return 0;
        }

        final int[] computed = new int[amount];
        for (int coin : coins) {
            if (coin < amount) {
                computed[coin] = 1;
            } else if (coin == amount) {
                return 1;
            }
        }

        return coinChange(coins, amount, computed);
    }

    public static int coinChange(int[] coins, int amount, int[] computed) {
        int min = -1;

        for (int coin : coins) {
            final int remained = amount - coin;
            if (remained > 0) {
                final Integer result0 = computed[remained];
                final int result;
                if (result0 == 0) {
                    result = coinChange(coins, remained, computed);
                    computed[remained] = result;
                } else {
                    result = result0;
                }
                if (result != -1) {
                    if (min == -1) {
                        min = result + 1;
                    } else {
                        min = Math.min(min, result + 1);
                    }
                }
            } else if (remained == 0) {
                return 1;
            }
        }

        return min;
    }
}
// @lc code=end

