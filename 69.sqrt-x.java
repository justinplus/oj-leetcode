/*
 * @lc app=leetcode id=69 lang=java
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
   public int mySqrt(int x) {
        int left = 0, right = x;
        while (left < right - 1) {
            // NOTE: left + right would overflow in this case
            final long mid = (left + right) / 2;
            final long square = mid * mid;
            // NOTE: overflow
            if (square == x) {
                return (int) mid;
            } else if (square < x) {
                left = (int) mid;
            } else {
                right = (int) mid - 1;
            }
        }

        // test Integer.MAX_VALUE, no need to convert to long here
        return right * right <= x ? right : left;
    } 
}
// @lc code=end
