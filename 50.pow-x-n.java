/*
 * @lc app=leetcode id=50 lang=java
 *
 * [50] Pow(x, n)
 */

// @lc code=start
// TODO: review
class Solution {
    public double myPow(double x, int n) {
        final int absN = Math.abs(n);

        double result = 1;
        double product = x;
        int mask = 1;
        for (int i = indexOfFirstBit(absN); i >= 0; --i, mask <<= 1, product *= product) {
            if ((absN & mask) != 0) {
                result *= product;
            }
        }

        return n >= 0 ? result : 1 / result;
    }

    private static int indexOfFirstBit(int n) {
        int mask = 1 << 31;
        for (int i = 0; i < 32; ++i, mask >>>= 1) {
            if ((n & mask) != 0) {
                return 32 - i - 1;
            }
        }
        return 0;
    }
}
// @lc code=end

