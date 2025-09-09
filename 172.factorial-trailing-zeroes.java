/*
 * @lc app=leetcode id=172 lang=java
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
class Solution {
    public int trailingZeroes(int n) {
        int result = 0;
        while (n > 0) {
            n = n / 5;
            result += n;
        }

        return result;
    }
}
// @lc code=end

