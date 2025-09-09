/*
 * @lc app=leetcode id=9 lang=java
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int xx = x;
        long reversed = 0;
        while (xx > 0) {
            reversed += reversed * 10 + xx % 10;
            xx /= 10;
        }

        return reversed == (long) x;
    }
}
// @lc code=end

